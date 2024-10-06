// 2. Write a multi client-server socket program to authenticate the username and password entered by the user at client.
// Assume server has a file called user.txt containing username and password stored per line and separated a comma and ended by semicolon. 
// Display ‘Successful login’ or ‘login Denied’ message to the respective client.
// Example: userABC, user123; similarly, next record in the next line.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 12345
#define BUF_SIZE 1024
#define MAX_CLIENTS 5

// Function to authenticate user
int authenticate(const char *username, const char *password) {
    FILE *file = fopen("user.txt", "r");
    if (!file) {
        perror("Unable to open user.txt");
        return 0;
    }

    char line[BUF_SIZE];
    char stored_user[BUF_SIZE], stored_pass[BUF_SIZE];

    // Check each line in the file for username and password
    while (fgets(line, sizeof(line), file)) {
        // Extract username and password
        sscanf(line, "%[^,],%[^;];", stored_user, stored_pass);
        if (strcmp(username, stored_user) == 0 && strcmp(password, stored_pass) == 0) {
            fclose(file);
            return 1;  // Successful login
        }
    }

    fclose(file);
    return 0;  // Login denied
}

// Function to handle each client in a separate thread
void *handle_client(void *arg) {
    int client_sock = *((int *)arg);
    free(arg);
    char buffer[BUF_SIZE], username[BUF_SIZE], password[BUF_SIZE];

    // Receive username and password
    recv(client_sock, buffer, BUF_SIZE, 0);
    sscanf(buffer, "%[^,],%s", username, password);

    // Authenticate user
    if (authenticate(username, password)) {
        send(client_sock, "Successful login", strlen("Successful login"), 0);
    } else {
        send(client_sock, "Login Denied", strlen("Login Denied"), 0);
    }

    close(client_sock);
    return NULL;
}

int main() {
    int server_sock, client_sock, *new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    pthread_t thread_id;

    // Create a TCP socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    printf("Server is waiting for clients...\n");

    // Accept clients in a loop
    while ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len))) {
        printf("Client connected\n");

        // Create a new socket for the client
        new_sock = malloc(sizeof(int));
        *new_sock = client_sock;

        // Handle the client in a separate thread
        if (pthread_create(&thread_id, NULL, handle_client, (void *)new_sock) < 0) {
            perror("Could not create thread");
            free(new_sock);
            close(client_sock);
        }

        pthread_detach(thread_id);  // Detach thread for automatic cleanup
    }

    if (client_sock < 0) {
        perror("Accept failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    close(server_sock);
    return 0;
}
