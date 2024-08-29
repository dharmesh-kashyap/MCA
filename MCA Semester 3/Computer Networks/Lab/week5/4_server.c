#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <math.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void calculate_roots(double a, double b, double c, char* result) {
    double discriminant = b * b - 4 * a * c;
    double root1, root2;

    if (a == 0) {
        if (b == 0) {
            strcpy(result, "Invalid equation. a and b cannot both be 0.");
        } else {
            // Linear equation: bx + c = 0
            root1 = -c / b;
            snprintf(result, BUFFER_SIZE, "Linear equation, Root: %.2f", root1);
        }
    } else if (discriminant > 0) {
        // Two distinct real roots
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        snprintf(result, BUFFER_SIZE, "Two distinct real roots: Root1 = %.2f, Root2 = %.2f", root1, root2);
    } else if (discriminant == 0) {
        // One real root
        root1 = -b / (2 * a);
        snprintf(result, BUFFER_SIZE, "One real root: Root = %.2f", root1);
    } else {
        // Complex roots
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        snprintf(result, BUFFER_SIZE, "Complex roots: Root1 = %.2f + %.2fi, Root2 = %.2f - %.2fi",
                 realPart, imaginaryPart, realPart, imaginaryPart);
    }
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    double a, b, c;

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
        // Receive coefficients from the client
        int valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread <= 0) {
            perror("Read failed");
            break;
        }

        sscanf(buffer, "%lf %lf %lf", &a, &b, &c);
        printf("Received coefficients - a: %.2f, b: %.2f, c: %.2f\n", a, b, c);

        // Calculate the roots
        char result[BUFFER_SIZE] = {0};
        calculate_roots(a, b, c, result);

        // Send the result back to the client
        send(new_socket, result, strlen(result), 0);
    }

    close(new_socket);
    close(server_fd);

    return 0;
}

