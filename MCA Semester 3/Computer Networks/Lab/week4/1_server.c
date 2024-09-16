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

void sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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

    sort(msg.array, msg.size);

    msg.msg_type = 2; 
    msgsnd(msgid, &msg, sizeof(msg), 0);

    printf("Server: Sorted array sent back to client.\n");

    return 0;
}

