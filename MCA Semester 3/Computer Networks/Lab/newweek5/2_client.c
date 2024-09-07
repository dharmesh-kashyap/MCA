#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in serv_addr = {AF_INET, htons(PORT)};
    char buffer[BUFFER_SIZE] = {0}, ip_address[BUFFER_SIZE] = {0};

    // Create socket and check
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0 || 
        inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0 || 
        connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Socket/Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to the server.\nEnter an IP address: ");
    fgets(ip_address, BUFFER_SIZE, stdin);
    ip_address[strcspn(ip_address, "\n")] = 0;  // Remove newline

    // Send IP and get server response
    send(sock, ip_address, strlen(ip_address), 0);
    if (read(sock, buffer, BUFFER_SIZE) > 0)
        printf("Server Response: %s\n", buffer);
    else
        perror("Read failed");

    close(sock);
    return 0;
}
