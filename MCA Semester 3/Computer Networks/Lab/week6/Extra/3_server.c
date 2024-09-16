// udp_server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

typedef struct {
    int account_number, pin;
    float balance;
} Account;

Account accounts[5] = {
    {1001, 1234, 5000.0},
    {1002, 2345, 3000.0},
    {1003, 3456, 7000.0},
    {1004, 4567, 1000.0},
    {1005, 5678, 2500.0}
};

void process_request(const char *req, char *res) {
    int acc_no, pin;
    float amount;
    sscanf(req, "%d %d %f", &acc_no, &pin, &amount);

    for (int i = 0; i < 5; i++) {
        if (accounts[i].account_number == acc_no && accounts[i].pin == pin) {
            if (accounts[i].balance >= amount + 1000) {
                accounts[i].balance -= amount;
                snprintf(res, BUFFER_SIZE, "Success: %.2f", accounts[i].balance);
            } else {
                strcpy(res, "Not enough balance.");
            }
            return;
        }
    }
    strcpy(res, "Invalid Account or PIN.");
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket failed");
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
        recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&client_addr, &len);
        buffer[strcspn(buffer, "\n")] = '\0';
        char response[BUFFER_SIZE];
        process_request(buffer, response);
        sendto(sockfd, response, strlen(response), 0, (struct sockaddr*)&client_addr, len);
    }

    close(sockfd);
    return 0;
}
