#include<stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int (*ptr)(int, int) = add; // Function pointer
    int result = ptr(5, 3);// Calling function through pointer
    
    int x=10, y=20;
    int *const = &x; // Constant pointer to x
    
   
   
    printf("Result: %d\n", result);
    return 0;
}