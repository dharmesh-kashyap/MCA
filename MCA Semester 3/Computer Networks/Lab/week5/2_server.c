#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to determine the class of the IP address
void determine_ip_class_and_mask(const char *ip_address, char *ip_class, char *default_mask) {
    unsigned char first_octet;
    sscanf(ip_address, "%hhu", &first_octet); // Extract the first octet of the IP address

    if (first_octet >= 1 && first_octet <= 126) {
        *ip_class = 'A';
        strcpy(default_mask, "255.0.0.0");
    } else if (first_octet >= 128 && first_octet <= 191) {
        *ip_class = 'B';
        strcpy(default_mask, "255.255.0.0");
    } else if (first_octet >= 192 && first_octet <= 223) {
        *ip_class = 'C';
        strcpy(default_mask, "255.255.255.0");
    } else if (first_octet >= 224 && first_octet <= 239) {
        *ip_class = 'D';
        strcpy(default_mask, "Multicast (no subnet mask)");
    } else if (first_octet >= 240 && first_octet <= 255) {
        *ip_class = 'E';
        strcpy(default_mask, "Reserved (no subnet mask)");
    } else {
        *ip_class = 'N';
        strcpy(default_mask, "Invalid IP");
    }
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char ip_class, default_mask[BUFFER_SIZE];

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

    // Read the IP address sent by the client
    int valread = read(new_socket, buffer, BUFFER_SIZE);
    if (valread > 0) {
        printf("Received IP address: %s\n", buffer);

        // Determine the class and default mask of the IP address
        determine_ip_class_and_mask(buffer, &ip_class, default_mask);

        // Send the class and default mask back to the client
        snprintf(buffer, BUFFER_SIZE, "Class: %c, Default Mask: %s", ip_class, default_mask);
        send(new_socket, buffer, strlen(buffer), 0);
    } else {
        perror("Read failed");
    }

    close(new_socket);
    close(server_fd);

    return 0;
}

