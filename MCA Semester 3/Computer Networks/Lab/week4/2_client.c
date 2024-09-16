#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

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

    printf("Enter first number: ");
    scanf("%f", &msg.num1);
    printf("Enter second number: ");
    scanf("%f", &msg.num2);
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &msg.operation);

    msg.msg_type = 1;
    msgsnd(msgid, &msg, sizeof(msg), 0);

    msgrcv(msgid, &result_msg, sizeof(result_msg), 2, 0);

    printf("Result: %f\n", result_msg.result);

    return 0;
}

