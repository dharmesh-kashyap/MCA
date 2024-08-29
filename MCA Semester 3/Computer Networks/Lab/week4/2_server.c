#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_SIZE 100

struct message {
    long msg_type;
    float num1;
    float num2;
    char operation;
};

struct result_message {
    long msg_type;
    float result;
};

int main() {
    key_t key;
    int msgid;
    struct message msg;
    struct result_message result_msg;

    key = ftok("progfile", 65);

    msgid = msgget(key, 0666 | IPC_CREAT);

    msgrcv(msgid, &msg, sizeof(msg), 1, 0);

    switch (msg.operation) {
        case '+':
            result_msg.result = msg.num1 + msg.num2;
            break;
        case '-':
            result_msg.result = msg.num1 - msg.num2;
            break;
        case '*':
            result_msg.result = msg.num1 * msg.num2;
            break;
        case '/':
            if (msg.num2 != 0) {
                result_msg.result = msg.num1 / msg.num2;
            } else {
                printf("Error: Division by zero.\n");
                result_msg.result = 0;
            }
            break;
        default:
            printf("Invalid operation.\n");
            result_msg.result = 0;
            break;
    }

    result_msg.msg_type = 2; // Change message type for response
    msgsnd(msgid, &result_msg, sizeof(result_msg), 0);

    printf("Server: Calculation result sent back to client.\n");

    return 0;
}

