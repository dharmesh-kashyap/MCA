#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 5555
#define BUFFER_SIZE 1024

void *receive_messages(void *client_socket) {
    int sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    int nbytes;

    while ((nbytes = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[nbytes] = '\0';
        printf("%s", buffer);
    }

    return NULL;
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    pthread_t tid;
    char message[BUFFER_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server.\n");

    // Create a thread to receive messages from the server
    pthread_create(&tid, NULL, receive_messages, &sock);

    // Sending messages in an infinite loop
    while (1) {
        fgets(message, sizeof(message), stdin);
        send(sock, message, strlen(message), 0);

        // End session if 'exit' is typed
        if (strncmp(message, "exit", 4) == 0) {
            printf("Ending chat session.\n");
            break;
        }
    }

    close(sock);
    return 0;
}
