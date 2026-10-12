#include <stdio.h>

int main(void)
{
    int rows, i, j;

    printf("Enter the number of rows: ");
    if (scanf("%d", &rows) != 1 || rows < 1) {
        printf("Please enter a positive number of rows.\n");
        return 1;
    }

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        for (j = 1; j <= 2 * (rows - i); j++) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    for (i = rows - 1; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        for (j = 1; j <= 2 * (rows - i); j++) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}