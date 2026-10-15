#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr= malloc(sizeof(int)); // Dynamically allocate memory for an integer
    if(ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;   
    }
    *ptr = 10; // Assign a value to the allocated memory
    printf("Value stored in dynamically allocated memory: %d\n", *ptr);
    free(ptr); // Free the allocated memory
    return 0;
    printf("Value after freeing memory: %d\n", *ptr); // Accessing freed memory (undefined behavior)
}