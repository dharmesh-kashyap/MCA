#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <math.h>

#define PORT 5555
#define BUFFER_SIZE 1024

// Function to calculate roots of quadratic equation
void calculate_roots(double a, double b, double c, char *result) {
    double discriminant, root1, root2, realPart, imagPart;

    discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        sprintf(result, "Roots are real and distinct: Root1 = %.2f, Root2 = %.2f", root1, root2);
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        sprintf(result, "Roots are real and equal: Root1 = Root2 = %.2f", root1);
    } else {
        realPart = -b / (2 * a);
        imagPart = sqrt(-discriminant) / (2 * a);
        sprintf(result, "Roots are complex: Root1 = %.2f + %.2fi, Root2 = %.2f - %.2fi", 
                realPart, imagPart, realPart, imagPart);
    }
}

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    double a, b, c;
    char buffer[BUFFER_SIZE], result[BUFFER_SIZE];

    // Receive the coefficients from the client
    recv(sock, buffer, sizeof(buffer), 0);
    sscanf(buffer, "%lf %lf %lf", &a, &b, &c);
    printf("Received coefficients from client: a = %.2f, b = %.2f, c = %.2f\n", a, b, c);

    // Calculate the roots of the quadratic equation
    calculate_roots(a, b, c, result);

    // Send the result to the client
    send(sock, result, strlen(result), 0);

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
