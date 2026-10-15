#include <stdio.h>

int main(void)
{
    char string[100];
    char *pointer = string;

    printf("Enter a string: ");
    while (pointer < string + sizeof string - 1 &&
           scanf("%c", pointer) == 1 && *pointer != '\n') {
        pointer++;
    }
    *pointer = '\0';

    printf("You entered: ");
    pointer = string;
    while (*pointer != '\0' && *pointer != '\n') {
        putchar(*pointer);
        pointer++;
    }
    putchar('\n');

    return 0;
}