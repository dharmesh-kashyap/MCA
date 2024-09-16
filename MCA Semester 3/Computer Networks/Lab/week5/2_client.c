#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    char ip_address[BUFFER_SIZE] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to the server.\n");

    // Get IP address from the user
    printf("Enter an IP address: ");
    fgets(ip_address, BUFFER_SIZE, stdin);
    ip_address[strcspn(ip_address, "\n")] = 0; // Remove the newline character

    // Send the IP address to the server
    send(sock, ip_address, strlen(ip_address), 0);

    // Receive the class and default mask from the server
    int valread = read(sock, buffer, BUFFER_SIZE);
    if (valread > 0) {
        printf("Server Response: %s\n", buffer);
    } else {
        perror("Read failed");
    }

    close(sock);

    return 0;
}

