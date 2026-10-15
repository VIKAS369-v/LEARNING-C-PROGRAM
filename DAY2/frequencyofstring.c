#include <stdio.h>

int main(void)
{
    char str[] = "abcdabc";  
    int frequency[26] = {0};

    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];

        if (ch >= 'a' && ch <= 'z')
        {
            frequency[ch - 'a']++;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            frequency[ch - 'A']++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (frequency[i] > 0)
        {
            printf("%c -> %d\n", 'a' + i, frequency[i]);
        }
    }

    return 0;
}