// udp_client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define CHUNK_SIZE 10

int main() {
    int sockfd, file_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE], file_name[BUFFER_SIZE] = "received_file.txt";

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) perror("Socket error"), exit(EXIT_FAILURE);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    printf("Enter file name: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));

    if ((file_fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0) perror("File error"), close(sockfd), exit(EXIT_FAILURE);

    while (recvfrom(sockfd, buffer, CHUNK_SIZE, 0, NULL, NULL) > 0) {
        if (strcmp(buffer, "EOF") == 0) break;
        write(file_fd, buffer, CHUNK_SIZE);
        printf("Received: %.*s\n", CHUNK_SIZE, buffer);
    }

    close(file_fd);
    close(sockfd);
    return 0;
}
