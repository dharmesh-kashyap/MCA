#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TICKETS 20
#define NUM_CATEGORIES 5
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
    int tickets[NUM_CATEGORIES] = {MAX_TICKETS, MAX_TICKETS, MAX_TICKETS, MAX_TICKETS, MAX_TICKETS};

    // Generate unique key
    key = ftok("ticket_booking", 65);

    // Create message queue and return id
    msgid = msgget(key, 0666 | IPC_CREAT);

    TicketRequest request;
    TicketResponse response;

    printf("Server is running...\n");

    while (1) {
        // Receive ticket booking request
        msgrcv(msgid, &request, sizeof(request) - sizeof(long), 1, 0);

        printf("Received request from %s for %d tickets in category %d\n", request.name, request.num_tickets, request.category);

        // Process the booking
        if (request.category < 1 || request.category > NUM_CATEGORIES) {
            snprintf(response.message, BUFFER_SIZE, "Invalid category selection.");
        } else if (tickets[request.category - 1] >= request.num_tickets) {
            tickets[request.category - 1] -= request.num_tickets;
            snprintf(response.message, BUFFER_SIZE, "Booking confirmed! Name: %s, Phone: %s, Category: %d, Tickets: %d",
                     request.name, request.phone, request.category, request.num_tickets);
        } else {
            snprintf(response.message, BUFFER_SIZE, "Booking failed! Not enough tickets available in category %d.", request.category);
        }

        response.msg_type = 2;
        // Send booking response
        msgsnd(msgid, &response, sizeof(response) - sizeof(long), 0);
    }

    return 0;
}

