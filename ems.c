//EVENT MANAGEMENT SYSTEM
#include <stdio.h>
#include <string.h>

struct Event {
    char name[50];
    char date[20];
    char location[50];
    int totalTickets;
    int ticketsSold;
};

struct Attendee {
    char name[50];
    char email[50];
};

void createEvent(struct Event *event) {
    printf("Enter Event Name: ");
    scanf("%s", event->name);

    printf("Enter Event Date: ");
    scanf("%s", event->date);

    printf("Enter Event Location: ");
    scanf("%s", event->location);

    printf("Enter Total Tickets: ");
    
    scanf("%d", &event->totalTickets);

    event->ticketsSold = 0;
    printf("Event created successfully!\n\n");
}

void registerAttendee(struct Event *event, struct Attendee *attendee) {
    if (event->ticketsSold < event->totalTickets) {
        printf("Enter Attendee Name: ");
        scanf("%s", attendee->name);

        printf("Enter Attendee Email: ");
        scanf("%s", attendee->email);

        printf("\nAttendee %s registered for the event '%s' on %s at %s.\n\n", attendee->name, event->name, event->date, event->location);

        event->ticketsSold++;
    } else {
        printf("Sorry, the event is sold out. No more tickets available.\n\n");
    }
}

void editEvent(struct Event *event) {
    printf("Enter new Event Name: ");
    scanf("%s", event->name);

    printf("Enter new Event Date: ");
    scanf("%s", event->date);

    printf("Enter new Event Location: ");
    scanf("%s", event->location);

    printf("Enter new Total Tickets: ");
    scanf("%d", &event->totalTickets);

    printf("Event edited successfully!\n\n");
}

void deleteEvent(struct Event *event) {
    strcpy(event->name, "");
    strcpy(event->date, "");
    strcpy(event->location, "");
    event->totalTickets = 0;
    event->ticketsSold = 0;

    printf("Event deleted successfully!\n\n");
}

void displayRemainingTickets(struct Event *event) {
    int remainingTickets = event->totalTickets - event->ticketsSold;
    printf("Remaining Tickets for '%s': %d\n\n", event->name, remainingTickets);
}

int main() {
    struct Event currentEvent;
    struct Attendee currentAttendee;

    int choice;

    do {
        printf("Event Management System\n");
        printf("1. Create Event\n");
        printf("2. Register Attendee\n");
        printf("3. Edit Event\n");
        printf("4. Delete Event\n");
        printf("5. Display Remaining Tickets\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createEvent(&currentEvent);
                break;
            case 2:
                if (strlen(currentEvent.name) == 0) {
                    printf("Please create an event first.\n\n");
                } else {
                    registerAttendee(&currentEvent, &currentAttendee);
                }
                break;
            case 3:
                if (strlen(currentEvent.name) == 0) {
                    printf("No event to edit. Please create an event first.\n\n");
                } else {
                    editEvent(&currentEvent);
                }
                break;
            case 4:
                if (strlen(currentEvent.name) == 0) {
                    printf("No event to delete. Please create an event first.\n\n");
                } else {
                    deleteEvent(&currentEvent);
                }
                break;
            case 5:
                if (strlen(currentEvent.name) == 0) {
                    printf("No event to display remaining tickets. Please create an event first.\n\n");
                } else {
                    displayRemainingTickets(&currentEvent);
                }
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n\n");
        }
    } while (choice != 6);

    return 0;
}
