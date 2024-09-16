#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    char *exit_message = "exit";

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket error");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert address and connect
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0 || 
        connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection error");
        exit(EXIT_FAILURE);
    }

    printf("Connected to the server.\n");

    while (1) {
        // Get and send message
        printf("Client: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(sock, buffer, strlen(buffer), 0);

        // End session
        if (strncmp(buffer, exit_message, strlen(exit_message)) == 0) {
            printf("Chat ended.\n");
            break;
        }

        // Receive and display server message
        memset(buffer, 0, BUFFER_SIZE);
        if (read(sock, buffer, BUFFER_SIZE) < 0) {
            perror("Read error");
            break;
        }

        printf("Server: %s\n", buffer);
    }

    close(sock);
    return 0;
}
