#include <limits.h>
#include <stdio.h>

int main(void)
{
    long long stairs, step;
    unsigned long long ways[6] = {1, 0, 0, 0, 0, 0};

    printf("Enter the number of stairs: ");
    if (scanf("%lld", &stairs) != 1 || stairs < 0) {
        printf("Please enter a non-negative number of stairs.\n");
        return 1;
    }

    for (step = 1; step <= stairs; step++) {
        unsigned long long current_ways = 0;
        int move;

        for (move = 1; move <= 6 && move <= step; move++) {
            unsigned long long previous_ways = ways[(step - move) % 6];

            if (ULLONG_MAX - current_ways < previous_ways) {
                printf("The number of ways is too large to represent.\n");
                return 1;
            }
            current_ways += previous_ways;
        }

        ways[step % 6] = current_ways;
    }

    printf("Number of ways: %llu\n", ways[stairs % 6]);
    return 0;
}