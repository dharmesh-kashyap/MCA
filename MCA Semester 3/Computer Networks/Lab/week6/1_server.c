#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    socklen_t addr_len = sizeof(client_addr);

    // Create UDP socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set up server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to the port
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        // Receive message from client
        ssize_t len = recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &addr_len);
        if (len < 0) {
            perror("Receive failed");
            break;
        }
        buffer[len] = '\0';  // Null-terminate the received message
        printf("Client: %s\n", buffer);

        // Check if client wants to end the chat
        if (strcmp(buffer, "exit") == 0) {
            printf("Chat ended by client.\n");
            break;
        }

        // Send response to client
        printf("Server: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';  // Remove newline character

        if (sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr *)&client_addr, addr_len) < 0) {
            perror("Send failed");
            break;
        }

        // Check if server wants to end the chat
        if (strcmp(buffer, "exit") == 0) {
            printf("Chat ended by server.\n");
            break;
        }
    }

    close(sock);
    return 0;
}
