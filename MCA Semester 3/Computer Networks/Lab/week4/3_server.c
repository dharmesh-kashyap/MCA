#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TEXT 512
#define SHIFT 3 

struct message {
    long msg_type;
    char text[MAX_TEXT];
};

void cipher_text(char *text) {
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' + SHIFT) % 26) + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + SHIFT) % 26) + 'A';
        }
    }
}

int main() {
    key_t key;
    int msgid;
    struct message msg;
 
    key = ftok("progfile", 65);

    msgid = msgget(key, 0666 | IPC_CREAT);

    msgrcv(msgid, &msg, sizeof(msg), 1, 0);

    printf("Server: Received text: %s\n", msg.text);

    cipher_text(msg.text);

    msg.msg_type = 2; 
    msgsnd(msgid, &msg, sizeof(msg), 0);

    printf("Server: Ciphered text sent back to client.\n");

    return 0;
}

