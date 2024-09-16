// udp_server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void get_ip_info(const char *ip, char *info) {
    unsigned char first_octet;
    sscanf(ip, "%hhu", &first_octet);
    if (first_octet <= 126) strcpy(info, "Class A, Mask: 255.0.0.0");
    else if (first_octet <= 191) strcpy(info, "Class B, Mask: 255.255.0.0");
    else if (first_octet <= 223) strcpy(info, "Class C, Mask: 255.255.255.0");
    else if (first_octet <= 239) strcpy(info, "Class D, No mask");
    else strcpy(info, "Class E, Reserved");
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    while (1) {
        recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&client_addr, &addr_len);
        buffer[strcspn(buffer, "\n")] = '\0';  // Remove newline
        printf("Received IP: %s\n", buffer);

        char info[BUFFER_SIZE];
        get_ip_info(buffer, info);
        sendto(sockfd, info, strlen(info), 0, (struct sockaddr*)&client_addr, addr_len);
    }

    close(sockfd);
    return 0;
}
