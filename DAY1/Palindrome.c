#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_line(const char *prompt, char *text, size_t size)
{
    printf("%s", prompt);
    if (fgets(text, (int)size, stdin) == NULL)
    {
        return 0;
    }

    size_t length = strlen(text);
    if (length > 0 && text[length - 1] == '\n')
    {
        text[length - 1] = '\0';
    }
    else if (!feof(stdin))
    {
        int character;
        while ((character = getchar()) != '\n' && character != EOF)
        {
        }
        printf("Input is too long.\n");
        return 0;
    }

    return 1;
}

void trim(char *text)
{
    char *start = text;
    while (isspace((unsigned char)*start))
    {
        start++;
    }

    if (start != text)
    {
        memmove(text, start, strlen(start) + 1);
    }

    size_t length = strlen(text);
    while (length > 0 && isspace((unsigned char)text[length - 1]))
    {
        text[--length] = '\0';
    }
}

int is_palindrome_text(const char *text)
{
    size_t left = 0;
    size_t right = strlen(text);

    while (left < right)
    {
        while (left < right && isspace((unsigned char)text[left]))
        {
            left++;
        }
        while (left < right && isspace((unsigned char)text[right - 1]))
        {
            right--;
        }
        if (left < right &&
            tolower((unsigned char)text[left]) !=
                tolower((unsigned char)text[right - 1]))
        {
            return 0;
        }
        left++;
        right--;
    }

    return 1;
}

int is_decimal_palindrome(const char *text, int *valid)
{
    char digits[256];
    size_t digit_count = 0;
    int decimal_point_seen = 0;
    size_t index = 0;
    *valid = 0;

    if (text[index] == '+' || text[index] == '-')
    {
        index++;
    }

    for (; text[index] != '\0'; index++)
    {
        if (isdigit((unsigned char)text[index]))
        {
            digits[digit_count++] = text[index];
        }
        else if (text[index] == '.' && !decimal_point_seen)
        {
            decimal_point_seen = 1;
        }
        else
        {
            return 0;
        }
    }

    if (digit_count == 0)
    {
        return 0;
    }
    *valid = 1;

    for (size_t left = 0, right = digit_count - 1; left < right; left++, right--)
    {
        if (digits[left] != digits[right])
        {
            return 0;
        }
    }

    return 1;
}

int equals_ignore_case(const char *left, const char *right)
{
    while (*left != '\0' && *right != '\0')
    {
        if (tolower((unsigned char)*left) != tolower((unsigned char)*right))
        {
            return 0;
        }
        left++;
        right++;
    }

    return *left == '\0' && *right == '\0';
}

int main(void)
{
    char input[256];
    char choice_text[32];
    char *end;
    long choice;

    printf("Palindrome checker\n");
    printf("1. Integer\n");
    printf("2. Character or word\n");
    printf("3. Decimal number\n");
    printf("4. Boolean (true/false or 1/0)\n");

    if (!read_line("Choose an option (1-4): ", choice_text, sizeof(choice_text)))
    {
        return 1;
    }

    errno = 0;
    choice = strtol(choice_text, &end, 10);
    while (isspace((unsigned char)*end))
    {
        end++;
    }
    if (errno != 0 || end == choice_text || *end != '\0' || choice < 1 || choice > 4)
    {
        printf("Please choose a number from 1 to 4.\n");
        return 1;
    }

    if (!read_line("Enter a value: ", input, sizeof(input)))
    {
        return 1;
    }
    trim(input);

    if (choice == 1)
    {
        long parsed_number;
        long long reversed_number = 0;
        int original_number;

        errno = 0;
        parsed_number = strtol(input, &end, 10);
        if (errno != 0 || end == input || *end != '\0' ||
            parsed_number < INT_MIN || parsed_number > INT_MAX)
        {
            printf("Please enter a valid integer.\n");
            return 1;
        }

        original_number = (int)parsed_number;
        if (original_number >= 0)
        {
            int number = original_number;
            while (number > 0)
            {
                reversed_number = reversed_number * 10 + number % 10;
                number /= 10;
            }
        }

        if (original_number >= 0 && original_number == reversed_number)
        {
            printf("%d is a palindrome.\n", original_number);
        }
        else
        {
            printf("%d is not a palindrome.\n", original_number);
        }
    }
    else if (choice == 2)
    {
        if (input[0] == '\0')
        {
            printf("Please enter a character or word.\n");
            return 1;
        }

        if (is_palindrome_text(input))
        {
            printf("\"%s\" is a palindrome.\n", input);
        }
        else
        {
            printf("\"%s\" is not a palindrome.\n", input);
        }
    }
    else if (choice == 3)
    {
        int valid;
        int palindrome = is_decimal_palindrome(input, &valid);

        if (!valid)
        {
            printf("Please enter a valid decimal number (without exponent notation).\n");
            return 1;
        }

        if (palindrome)
        {
            printf("%s is a palindrome (ignoring the decimal point and sign).\n", input);
        }
        else
        {
            printf("%s is not a palindrome (ignoring the decimal point and sign).\n", input);
        }
    }
    else
    {
        if (equals_ignore_case(input, "true") || equals_ignore_case(input, "false") ||
            strcmp(input, "1") == 0 || strcmp(input, "0") == 0)
        {
            printf("%s is a valid boolean value; palindrome checking does not apply to booleans.\n",
                   input);
        }
        else
        {
            printf("Please enter true, false, 1, or 0.\n");
            return 1;
        }
    }

    return 0;
}
