#include <stdio.h>
#include <stdlib.h>

static long long hours_needed(const int piles[], int n, int speed, long long hour_limit)
{
    long long hours = 0;

    for (int i = 0; i < n; i++)
    {
        hours += piles[i] / speed;
        if (piles[i] % speed != 0)
        {
            hours++;
        }

        if (hours > hour_limit)
        {
            return hours;
        }
    }

    return hours;
}

int main(void)
{
    int n;
    long long h;

    printf("Enter number of piles and available hours: ");
    if (scanf("%d %lld", &n, &h) != 2 || n <= 0 || h <= 0)
    {
        fprintf(stderr, "Invalid number of piles or hours.\n");
        return 1;
    }

    int *piles = malloc((size_t)n * sizeof(*piles));
    if (piles == NULL)
    {
        fprintf(stderr, "Unable to allocate memory for the piles.\n");
        return 1;
    }

    int max_pile = 0;
    long long non_empty_piles = 0;

    printf("Enter the banana count in each pile: ");
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &piles[i]) != 1 || piles[i] < 0)
        {
            fprintf(stderr, "Pile sizes must be non-negative integers.\n");
            free(piles);
            return 1;
        }

        if (piles[i] > max_pile)
        {
            max_pile = piles[i];
        }
        if (piles[i] > 0)
        {
            non_empty_piles++;
        }
    }

    if (non_empty_piles == 0)
    {
        printf("Minimum eating speed: 0\n");
        free(piles);
        return 0;
    }

    if (h < non_empty_piles)
    {
        printf("It is not possible to finish all the bananas within %lld hours.\n", h);
        free(piles);
        return 0;
    }

    int low = 1;
    int high = max_pile;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (hours_needed(piles, n, mid, h) <= h)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    printf("Minimum eating speed: %d bananas per hour\n", low);
    free(piles);
    return 0;
}
