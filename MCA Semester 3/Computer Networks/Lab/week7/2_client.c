#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUF_SIZE 1024

int main() {
    int client_sock;
    struct sockaddr_in server_addr;
    char username[BUF_SIZE], password[BUF_SIZE], buffer[BUF_SIZE];

    // Create a TCP socket
    client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Use server IP if needed
    server_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(client_sock);
        exit(EXIT_FAILURE);
    }

    // Get username and password from the user
    printf("Enter username: ");
    fgets(username, BUF_SIZE, stdin);
    username[strcspn(username, "\n")] = 0; // Remove newline character

    printf("Enter password: ");
    fgets(password, BUF_SIZE, stdin);
    password[strcspn(password, "\n")] = 0; // Remove newline character

    // Send username and password to the server
    snprintf(buffer, BUF_SIZE, "%s,%s", username, password);
    send(client_sock, buffer, strlen(buffer), 0);

    // Receive response from the server
    recv(client_sock, buffer, BUF_SIZE, 0);
    printf("Server response: %s\n", buffer);

    // Close the socket
    close(client_sock);

    return 0;
}
