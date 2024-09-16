#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define BUFFER_SIZE 1024

typedef struct {
    long msg_type;
    char name[50];
    char phone[15];
    int category;
    int num_tickets;
} TicketRequest;

typedef struct {
    long msg_type;
    char message[BUFFER_SIZE];
} TicketResponse;

int main() {
    key_t key;
    int msgid;

    TicketRequest request;
    TicketResponse response;

    // Generate unique key
    key = ftok("ticket_booking", 65);

    // Create message queue and return id
    msgid = msgget(key, 0666 | IPC_CREAT);

    // Get user input
    printf("Enter Name: ");
    fgets(request.name, 50, stdin);
    request.name[strcspn(request.name, "\n")] = '\0';  // Remove trailing newline

    printf("Enter Phone: ");
    fgets(request.phone, 15, stdin);
    request.phone[strcspn(request.phone, "\n")] = '\0';  // Remove trailing newline

    printf("Enter Ticket Category (1-5): ");
    scanf("%d", &request.category);

    printf("Enter Number of Tickets: ");
    scanf("%d", &request.num_tickets);

    // Set message type
    request.msg_type = 1;

    // Send booking request
    msgsnd(msgid, &request, sizeof(request) - sizeof(long), 0);

    // Receive booking response
    msgrcv(msgid, &response, sizeof(response) - sizeof(long), 2, 0);

    // Display the response
    printf("Server Response: %s\n", response.message);

    return 0;
}

