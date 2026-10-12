#include <stdio.h>

int main(void)
{
    int amountPaid;
    int amountDue;
    int change;
    int count;

    printf("Enter the amount paid: ");
    if (scanf("%d", &amountPaid) != 1 || amountPaid < 0)
    {
        printf("Please enter a valid non-negative amount.\n");
        return 1;
    }

    printf("Enter the amount due: ");
    if (scanf("%d", &amountDue) != 1 || amountDue < 0)
    {
        printf("Please enter a valid non-negative amount.\n");
        return 1;
    }

    if (amountPaid < amountDue)
    {
        printf("The amount paid is not enough.\n");
        return 1;
    }

    change = amountPaid - amountDue;
    printf("Change to return: %d\n", change);

    count = change / 100;
    printf("100: %d\n", count);
    change = change % 100;

    count = change / 50;
    printf("50: %d\n", count);
    change = change % 50;

    count = change / 20;
    printf("20: %d\n", count);
    change = change % 20;

    count = change / 10;
    printf("10: %d\n", count);
    change = change % 10;

    count = change / 5;
    printf("5: %d\n", count);
    change = change % 5;

    count = change / 2;
    printf("2: %d\n", count);
    change = change % 2;

    printf("1: %d\n", change);

    return 0;
}