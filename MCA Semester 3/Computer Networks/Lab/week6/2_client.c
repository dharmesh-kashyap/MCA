// udp_client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE], ip_address[BUFFER_SIZE];

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    printf("Enter IP address: ");
    fgets(ip_address, BUFFER_SIZE, stdin);
    ip_address[strcspn(ip_address, "\n")] = '\0';  // Remove newline

    sendto(sockfd, ip_address, strlen(ip_address), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));

    recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL);
    printf("Server Response: %s\n", buffer);

    close(sockfd);
    return 0;
}
