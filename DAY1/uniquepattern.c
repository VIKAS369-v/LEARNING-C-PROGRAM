#include <stdio.h>

int main(void)
{
    int rows, i, j;

    printf("Enter the number of rows: ");
    if (scanf("%d", &rows) != 1 || rows < 5) {
        printf("Please enter at least 5 rows.\n");
        return 1;
    }

    for (i = 1; i < rows; i++) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        for (j = 1; j <= 3 * (rows - i); j++) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    for (j = 1; j <= 2 * rows; j++) {
        printf("*");
    }
    printf("\n");

    for (j = 1; j <= rows - 2; j++) {
        printf("*");
    }
    printf("  ");
    for (j = 1; j <= rows - 2; j++) {
        printf("*");
    }
    printf("\n");

    for (j = 1; j <= rows - 2; j++) {
        printf("*");
    }
    printf("  *  ");
    for (j = 1; j <= rows - 2; j++) {
        printf("*");
    }
    printf("\n");

    for (j = 1; j <= rows - 3; j++) {
        printf("*");
    }
    printf("   ");
    for (j = 1; j <= rows - 3; j++) {
        printf("*");
    }
    printf("   ");
    for (j = 1; j <= rows - 3; j++) {
        printf("*");
    }
    printf("\n");

    for (j = 1; j <= rows - 4; j++) {
        printf("*");
    }
    printf("    ");
    for (j = 1; j <= rows - 2; j++) {
        printf("*");
    }
    printf("    ");
    for (j = 1; j <= rows - 4; j++) {
        printf("*");
    }
    printf("\n");

    return 0;
}