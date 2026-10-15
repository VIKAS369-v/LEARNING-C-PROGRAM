#include<stdio.h>

int main(){
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int (*ptr)[3] = arr; // Pointer to an array of 3 integers
    printf("%d ", (*ptr)[0]); // Print the first element of the first row
    printf("&+%d",(*ptr)[1][2]);

    printf("%d ", *(*((arr +1)+2)));


    return 0;
}