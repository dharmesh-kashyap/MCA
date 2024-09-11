// udp_server.c
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
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE], file_name[BUFFER_SIZE];

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) perror("Socket error"), exit(EXIT_FAILURE);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) perror("Bind error"), exit(EXIT_FAILURE);

    recvfrom(sockfd, file_name, BUFFER_SIZE, 0, (struct sockaddr*)&client_addr, &addr_len);
    file_name[strcspn(file_name, "\n")] = '\0';

    if ((file_fd = open(file_name, O_RDONLY)) < 0) {
        perror("File error");
        strcpy(buffer, "File not found");
        sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&client_addr, addr_len);
        close(sockfd);
        return 1;
    }

    while (read(file_fd, buffer, CHUNK_SIZE) > 0) sendto(sockfd, buffer, CHUNK_SIZE, 0, (struct sockaddr*)&client_addr, addr_len);
    strcpy(buffer, "EOF");
    sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&client_addr, addr_len);

    close(file_fd);
    close(sockfd);
    return 0;
}
