#include<stdio.h>

int main(void)

{
    int rows, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &rows); 

    for(i=2; i<=rows; i++){
        for(j=1;j<=rows-i;j++){
            printf("  ");
        }
        for(j=1;j<=i;j++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}