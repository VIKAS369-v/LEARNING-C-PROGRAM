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
        for (j = 1; j <= rows; j++) {
            if (i == 1 || i == rows || j == 1 || j == rows) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}
