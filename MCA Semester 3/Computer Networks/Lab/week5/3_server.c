#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

typedef struct {
    int account_number;
    int pin;
    float balance;
} Account;

// Pre-stored account information
Account accounts[5] = {
    {1001, 1234, 5000.0},
    {1002, 2345, 3000.0},
    {1003, 3456, 7000.0},
    {1004, 4567, 1000.0},
    {1005, 5678, 2500.0}
};

Account* validate_account(int account_number, int pin) {
    for (int i = 0; i < 5; i++) {
        if (accounts[i].account_number == account_number && accounts[i].pin == pin) {
            return &accounts[i];
        }
    }
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    // Accept the incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Client connected.\n");

    while (1) {
        // Receive account details and withdrawal amount from the client
        int valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread <= 0) {
            perror("Read failed");
            break;
        }

        int account_number, pin;
        float withdrawal_amount;
        sscanf(buffer, "%d %d %f", &account_number, &pin, &withdrawal_amount);

        printf("Received - Account: %d, PIN: %d, Withdrawal Amount: %.2f\n", account_number, pin, withdrawal_amount);

        // Validate the account and perform withdrawal
        Account *account = validate_account(account_number, pin);
        if (account == NULL) {
            snprintf(buffer, BUFFER_SIZE, "Invalid Account Number or PIN.");
        } else if (account->balance < withdrawal_amount + 1000) { // Ensure the account maintains a minimum balance of 1000
            snprintf(buffer, BUFFER_SIZE, "Not enough balance.");
        } else {
            account->balance -= withdrawal_amount;
            snprintf(buffer, BUFFER_SIZE, "Withdrawal successful. New Balance: %.2f", account->balance);
        }

        // Send the result back to the client
        send(new_socket, buffer, strlen(buffer), 0);
    }

    close(new_socket);
    close(server_fd);

    return 0;
}

