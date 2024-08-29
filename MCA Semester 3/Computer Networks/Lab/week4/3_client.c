#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TEXT 512

struct message {
    long msg_type;
    char text[MAX_TEXT];
};

int main() {
    key_t key;
    int msgid;
    struct message msg;

    key = ftok("progfile", 65);

    msgid = msgget(key, 0666 | IPC_CREAT);

    printf("Enter a line of text: ");
    fgets(msg.text, MAX_TEXT, stdin);

    msg.text[strcspn(msg.text, "\n")] = '\0';

    msg.msg_type = 1;
    msgsnd(msgid, &msg, sizeof(msg), 0);

    msgrcv(msgid, &msg, sizeof(msg), 2, 0);

    printf("Ciphered text: %s\n", msg.text);

    return 0;
}

