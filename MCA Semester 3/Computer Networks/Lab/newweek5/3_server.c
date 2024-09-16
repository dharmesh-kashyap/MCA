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
    {1001, 1234, 5000.0}, {1002, 2345, 3000.0}, {1003, 3456, 7000.0},
    {1004, 4567, 1000.0}, {1005, 5678, 2500.0}
};

// Validate account
Account* validate_account(int acc_no, int pin) {
    for (int i = 0; i < 5; i++)
        if (accounts[i].account_number == acc_no && accounts[i].pin == pin)
            return &accounts[i];
    return NULL;
}

int main() {
    int server_fd, new_socket, account_number, pin;
    float withdrawal_amount;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in address = {AF_INET, htons(PORT), INADDR_ANY};

    // Create and bind socket, then listen for connections
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0 || 
        bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0 || 
        listen(server_fd, 3) < 0) {
        perror("Socket/Bind/Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept client connection
    printf("Server is listening on port %d\n", PORT);
    if ((new_socket = accept(server_fd, NULL, NULL)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Receive and parse client data
        if (read(new_socket, buffer, BUFFER_SIZE) <= 0) break;
        sscanf(buffer, "%d %d %f", &account_number, &pin, &withdrawal_amount);

        // Validate and process withdrawal
        Account *account = validate_account(account_number, pin);
        if (!account) {
            snprintf(buffer, BUFFER_SIZE, "Invalid Account or PIN.");
        } else if (account->balance < withdrawal_amount + 1000) {
            snprintf(buffer, BUFFER_SIZE, "Insufficient balance.");
        } else {
            account->balance -= withdrawal_amount;
            snprintf(buffer, BUFFER_SIZE, "Success! New Balance: %.2f", account->balance);
        }

        send(new_socket, buffer, strlen(buffer), 0);  // Send response
    }

    close(new_socket);
    close(server_fd);
    return 0;
}
