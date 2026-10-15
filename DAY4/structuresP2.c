#include <stdio.h>
#include <stdlib.h>

#define MAX_TICKETS 100000
#define REGISTRATION_LENGTH 50

typedef struct {
    long ticketNumber;
    char registration[REGISTRATION_LENGTH];
    float grossWeight;
    float tareWeight;
} Ticket;

static float getNetWeight(const Ticket *ticket)
{
    return ticket->grossWeight - ticket->tareWeight;
}

static void printTicket(const Ticket *ticket)
{
    printf("Ticket Number: %ld\n", ticket->ticketNumber);
    printf("Vehicle Registration: %s\n", ticket->registration);
    printf("Gross Weight: %.2f\n", ticket->grossWeight);
    printf("Tare Weight: %.2f\n", ticket->tareWeight);
    printf("Net Weight: %.2f\n", getNetWeight(ticket));
}

int main(void)
{
    int count;
    if (scanf("%d", &count) != 1 || count <= 0 || count > MAX_TICKETS) {
        printf("INVALID COUNT\n");
        return 0;
    }

    Ticket *tickets = calloc((size_t)count, sizeof(*tickets));
    if (tickets == NULL) {
        fprintf(stderr, "Unable to allocate memory for tickets.\n");
        return 1;
    }

    double totalGross = 0.0;
    double totalTare = 0.0;
    double totalNet = 0.0;
    int heaviestIndex = 0;

    for (int i = 0; i < count; i++) {
        if (scanf("%ld %49s %f %f",
                  &tickets[i].ticketNumber,
                  tickets[i].registration,
                  &tickets[i].grossWeight,
                  &tickets[i].tareWeight) != 4) {
            fprintf(stderr, "Invalid ticket data.\n");
            free(tickets);
            return 1;
        }

        float netWeight = getNetWeight(&tickets[i]);
        totalGross += tickets[i].grossWeight;
        totalTare += tickets[i].tareWeight;
        totalNet += netWeight;

        if (netWeight > getNetWeight(&tickets[heaviestIndex])) {
            heaviestIndex = i;
        }
    }

    printf("Ticket Details:\n");
    for (int i = 0; i < count; i++) {
        printTicket(&tickets[i]);
        if (i + 1 < count) {
            putchar('\n');
        }
    }

    printf("\nTotal Gross Weight: %.2f\n", totalGross);
    printf("Total Tare Weight: %.2f\n", totalTare);
    printf("Total Net Weight: %.2f\n", totalNet);
    printf("\nHeaviest Load Ticket:\n");
    printTicket(&tickets[heaviestIndex]);

    free(tickets);
    return 0;
}