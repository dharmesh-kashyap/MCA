#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to determine IP class and default mask
void determine_ip_class_and_mask(const char *ip_address, char *ip_class, char *default_mask) {
    unsigned char first_octet;
    sscanf(ip_address, "%hhu", &first_octet);

    if (first_octet <= 126) *ip_class = 'A', strcpy(default_mask, "255.0.0.0");
    else if (first_octet <= 191) *ip_class = 'B', strcpy(default_mask, "255.255.0.0");
    else if (first_octet <= 223) *ip_class = 'C', strcpy(default_mask, "255.255.255.0");
    else if (first_octet <= 239) *ip_class = 'D', strcpy(default_mask, "Multicast (no subnet mask)");
    else *ip_class = 'E', strcpy(default_mask, "Reserved (no subnet mask)");
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address = {AF_INET, htons(PORT), INADDR_ANY};
    char buffer[BUFFER_SIZE] = {0}, ip_class, default_mask[BUFFER_SIZE];

    // Create, bind, listen, and accept connection
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0 || 
        bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0 || 
        listen(server_fd, 3) < 0 || 
        (new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&(int){sizeof(address)})) < 0) {
        perror("Socket/Bind/Listen/Accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Client connected.\n");

    // Read IP address, determine class and mask, and send response
    if (read(new_socket, buffer, BUFFER_SIZE) > 0) {
        printf("Received IP address: %s\n", buffer);
        determine_ip_class_and_mask(buffer, &ip_class, default_mask);
        snprintf(buffer, BUFFER_SIZE, "Class: %c, Default Mask: %s", ip_class, default_mask);
        send(new_socket, buffer, strlen(buffer), 0);
    } else perror("Read failed");

    close(new_socket);
    close(server_fd);
    return 0;
}
