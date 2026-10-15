#include<stdio.h>

int main(){
    char str[]= "Hello, World!";
    char *ptr = str; 
    // Pointer to the first character of the string
    while(*ptr != '\0') {
        printf("%c", *ptr); // Print each character using pointer
        ptr++; // Move to the next character
    }   
}
