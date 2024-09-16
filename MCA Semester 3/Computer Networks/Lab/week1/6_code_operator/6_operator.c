//Dharmesh Kashyap, Reg no: 230970133

//6. Accept two numbers and operator (+, -, *, /) as command line arguments. Perform numerical operation as per operator in the child and display the result.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 4) {
        printf("Usage: %s num1 num2 operator\n", argv[0]);
        return 1;
    }

    // Convert arguments to numbers
    double num1 = atof(argv[1]);
    double num2 = atof(argv[2]);
    char operator = argv[3][0];

    // Validate operator
    if (!(operator == '+' || operator == '-' || operator == '*' || operator == '/')) {
        printf("Error: Invalid operator. Use +, -, *, or /.\n");
        return 1;
    }

    // Create child process
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        double result;
        switch (operator) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 == 0) {
                    printf("Child: Division by zero not allowed.\n");
                    return 1;
                }
                result = num1 / num2;
                break;
        }
        printf("Child: Result: %lf\n", result);
    } else {
        // Parent process
        wait(NULL); // Wait for child process to complete
        printf("Parent: Child process completed.\n");
    }

    return 0;
}

