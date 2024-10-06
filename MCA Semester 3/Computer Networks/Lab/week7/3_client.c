#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 12345
#define BUF_SIZE 1024

int main() {
    int client_sock;
    struct sockaddr_in server_addr;
    socklen_t addr_len = sizeof(server_addr);
    char file_name[BUF_SIZE], buffer[BUF_SIZE];
    FILE *new_file;

    // Create UDP socket
    client_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Use localhost or server IP
    server_addr.sin_port = htons(PORT);

    // Get file name from the user
    printf("Enter the file name to copy from the server: ");
    fgets(file_name, BUF_SIZE, stdin);

    // Send file name to server
    sendto(client_sock, file_name, strlen(file_name), 0, (struct sockaddr *)&server_addr, addr_len);

    // Open a new file to write the received content
    new_file = fopen("copied_file.txt", "w");
    if (!new_file) {
        perror("File creation failed");
        close(client_sock);
        exit(EXIT_FAILURE);
    }

    // Receive data from the server and write to the new file
    while (1) {
        int bytes_received = recvfrom(client_sock, buffer, BUF_SIZE, 0, (struct sockaddr *)&server_addr, &addr_len);
        buffer[bytes_received] = '\0';  // Null-terminate the buffer

        // Check for file-not-found message
        if (strcmp(buffer, "file-not-found") == 0) {
            printf("File not found on the server.\n");
            break;
        }

        // Check for EOF marker
        if (strcmp(buffer, "EOF") == 0) {
            printf("File copied successfully.\n");
            break;
        }

        // Write the received data to the new file
        fputs(buffer, new_file);
        printf("Received: %s\n", buffer);
    }

    // Clean up
    fclose(new_file);
    close(client_sock);

    return 0;
}
