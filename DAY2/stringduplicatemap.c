#include<stdio.h>
#include<stdbool.h>

int main(void)
{
    char str[] = "abcdabc";
    int hash[26] = {0};
    for(int i = 0; str[i] != '\0'; i++)
    {

     char ch = str[i];
     int index = ch - 'a';
     if(hash[index] == 1)
     {
         printf("Duplicate character found: %c\n", ch);
         return 0;
     }
     else {
        
         hash[index] = hash[index] + 1;
     }
    }
    printf("No duplicate characters found.\n");
    return 0;
}