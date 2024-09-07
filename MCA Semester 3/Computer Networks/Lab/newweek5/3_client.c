#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock, account_number, pin;
    float withdrawal_amount;
    struct sockaddr_in serv_addr = {AF_INET, htons(PORT)};
    char buffer[BUFFER_SIZE] = {0};

    // Create socket and check
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0 || 
        inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0 || 
        connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Socket/Connection failed");
        exit(EXIT_FAILURE);
    }

    // Get account details and withdrawal amount
    printf("Enter Account Number: "); scanf("%d", &account_number);
    printf("Enter PIN: "); scanf("%d", &pin);
    printf("Enter Withdrawal Amount: "); scanf("%f", &withdrawal_amount);

    // Send account details to server
    snprintf(buffer, BUFFER_SIZE, "%d %d %.2f", account_number, pin, withdrawal_amount);
    send(sock, buffer, strlen(buffer), 0);

    // Receive and display server response
    if (read(sock, buffer, BUFFER_SIZE) > 0)
        printf("Server Response: %s\n", buffer);
    else
        perror("Read failed");

    close(sock);
    return 0;
}
