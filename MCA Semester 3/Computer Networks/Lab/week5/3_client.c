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
    int account_number, pin;
    float withdrawal_amount;

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

    // Get account details and withdrawal amount from the user
    printf("Enter Account Number: ");
    scanf("%d", &account_number);
    printf("Enter PIN: ");
    scanf("%d", &pin);
    printf("Enter Withdrawal Amount: ");
    scanf("%f", &withdrawal_amount);

    // Send the account number, pin, and withdrawal amount to the server
    snprintf(buffer, BUFFER_SIZE, "%d %d %.2f", account_number, pin, withdrawal_amount);
    send(sock, buffer, strlen(buffer), 0);

    // Receive the result from the server
    int valread = read(sock, buffer, BUFFER_SIZE);
    if (valread > 0) {
        printf("Server Response: %s\n", buffer);
    } else {
        perror("Read failed");
    }

    close(sock);

    return 0;
}

