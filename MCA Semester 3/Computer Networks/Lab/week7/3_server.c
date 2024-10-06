// 3. Write a client-server socket program using UDP to copy the content of a file existing at server to the client. 
// Client accepts file name and sends to the server. 
// Server reads 10 characters at a time from the file and sends to client. 
// Client displays the data received and writes to another local file until entire file at server is copied to client’s new local file. 
// If file name doesn’t exist at the server, server sends “file-no found” message to the client and client ends the communication.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>

#define PORT 12345
#define BUF_SIZE 1024

void handle_client(int sock, struct sockaddr_in *client_addr, socklen_t addr_len) {
    char file_name[BUF_SIZE], buffer[BUF_SIZE];
    int file_desc, bytes_read;

    // Receive the file name from the client
    recvfrom(sock, file_name, BUF_SIZE, 0, (struct sockaddr *)client_addr, &addr_len);
    file_name[strcspn(file_name, "\n")] = 0; // Remove newline character if present

    // Check if file exists
    file_desc = open(file_name, O_RDONLY);
    if (file_desc == -1) {
        // File not found, send "file-not-found" message
        sendto(sock, "file-not-found", strlen("file-not-found"), 0, (struct sockaddr *)client_addr, addr_len);
        return;
    }

    // Read file 10 characters at a time and send to client
    while ((bytes_read = read(file_desc, buffer, 10)) > 0) {
        buffer[bytes_read] = '\0';  // Null-terminate the buffer
        sendto(sock, buffer, bytes_read, 0, (struct sockaddr *)client_addr, addr_len);
    }

    // Send EOF to signal the end of file
    sendto(sock, "EOF", strlen("EOF"), 0, (struct sockaddr *)client_addr, addr_len);
    close(file_desc);
}

int main() {
    int server_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create UDP socket
    server_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    printf("Server is ready and waiting for requests...\n");

    // Handle incoming client requests
    while (1) {
        handle_client(server_sock, &client_addr, addr_len);
    }

    close(server_sock);
    return 0;
}
