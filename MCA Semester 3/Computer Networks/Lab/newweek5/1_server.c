#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address = {AF_INET, htons(PORT), INADDR_ANY};
    char buffer[BUFFER_SIZE] = {0};

    // Create and bind socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0 || 
        bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Socket/Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen and accept connection
    if (listen(server_fd, 3) < 0 || 
        (new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&(int){sizeof(address)})) < 0) {
        perror("Listen/Accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Client connected.\n");

    // Chat loop
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        if (read(new_socket, buffer, BUFFER_SIZE) < 0) break;

        printf("Client: %s\n", buffer);
        if (strncmp(buffer, "exit", 4) == 0) break;

        printf("Server: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(new_socket, buffer, strlen(buffer), 0);
    }

    close(new_socket);
    close(server_fd);
    return 0;
}
