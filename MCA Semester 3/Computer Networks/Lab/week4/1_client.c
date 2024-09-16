#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_SIZE 100

struct message {
    long msg_type;
    int array[MAX_SIZE];
    int size;
};

int main() {
    key_t key;
    int msgid;
    struct message msg;

    key = ftok("progfile", 65);

    msgid = msgget(key, 0666 | IPC_CREAT);

    printf("Enter number of elements: ");
    scanf("%d", &msg.size);
    printf("Enter the elements: ");
    for (int i = 0; i < msg.size; i++) {
        scanf("%d", &msg.array[i]);
    }

    msg.msg_type = 1;
    msgsnd(msgid, &msg, sizeof(msg), 0);

    msgrcv(msgid, &msg, sizeof(msg), 2, 0);

    printf("Sorted array: ");
    for (int i = 0; i < msg.size; i++) {
        printf("%d ", msg.array[i]);
    }
    printf("\n");

    return 0;
}

