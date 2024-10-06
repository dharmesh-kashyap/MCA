// 2. Write a client-server socket program using UDP. Client accepts an IP address and sends to server. 
// Server receives IP address and displays it. Server process the IP address to identify the class of IP address (A, B, C, D, E). 
// Server sends class and default mask to the client via socket. Client displays the result.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 5555
#define BUFFER_SIZE 1024

// Function to determine the class and subnet mask of an IP address
void get_ip_class_and_mask(const char *ip, char *class, char *mask) {
    unsigned int first_octet;
    sscanf(ip, "%u", &first_octet);

    if (first_octet >= 1 && first_octet <= 126) {
        strcpy(class, "A");
        strcpy(mask, "255.0.0.0");
    } else if (first_octet >= 128 && first_octet <= 191) {
        strcpy(class, "B");
        strcpy(mask, "255.255.0.0");
    } else if (first_octet >= 192 && first_octet <= 223) {
        strcpy(class, "C");
        strcpy(mask, "255.255.255.0");
    } else if (first_octet >= 224 && first_octet <= 239) {
        strcpy(class, "D");
        strcpy(mask, "Not applicable (Multicast)");
    } else if (first_octet >= 240 && first_octet <= 255) {
        strcpy(class, "E");
        strcpy(mask, "Not applicable (Experimental)");
    } else {
        strcpy(class, "Unknown");
        strcpy(mask, "Unknown");
    }
}

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    char ip_class[10], subnet_mask[BUFFER_SIZE];

    // Receive the IP address from the client
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Received IP address from client: %s\n", buffer);

    // Determine the class and default mask
    get_ip_class_and_mask(buffer, ip_class, subnet_mask);

    // Send the class and default mask to the client
    sprintf(buffer, "Class: %s, Default Mask: %s", ip_class, subnet_mask);
    send(sock, buffer, strlen(buffer), 0);

    close(sock);
    free(client_socket);
    return NULL;
}

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t tid;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) == -1) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server started, waiting for connections...\n");

    while (1) {
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (new_socket == -1) {
            perror("Accept failed");
            continue;
        }

        int *client_sock_ptr = malloc(sizeof(int));
        *client_sock_ptr = new_socket;
        pthread_create(&tid, NULL, handle_client, client_sock_ptr);
    }

    close(server_socket);
    return 0;
}
