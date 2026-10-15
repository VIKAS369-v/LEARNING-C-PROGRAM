#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static void printSpiral(const int *matrix, int rows, int cols)
{
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;
    size_t printed = 0;

    printf("[");

    while (top <= bottom && left <= right) {
        for (int col = left; col <= right; col++) {
            if (printed++ > 0) {
                printf(",");
            }
            printf("%d", matrix[(size_t)top * (size_t)cols + (size_t)col]);
        }
        top++;

        for (int row = top; row <= bottom; row++) {
            if (printed++ > 0) {
                printf(",");
            }
            printf("%d", matrix[(size_t)row * (size_t)cols + (size_t)right]);
        }
        right--;

        if (top <= bottom) {
            for (int col = right; col >= left; col--) {
                if (printed++ > 0) {
                    printf(",");
                }
                printf("%d", matrix[(size_t)bottom * (size_t)cols + (size_t)col]);
            }
            bottom--;
        }

        if (left <= right) {
            for (int row = bottom; row >= top; row--) {
                if (printed++ > 0) {
                    printf(",");
                }
                printf("%d", matrix[(size_t)row * (size_t)cols + (size_t)left]);
            }
            left++;
        }
    }

    printf("]\n");
}

int main(void)
{
    int rows;
    int cols;

    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        fprintf(stderr, "Enter positive row and column counts.\n");
        return 1;
    }

    if ((size_t)rows > SIZE_MAX / (size_t)cols ||
        (size_t)rows * (size_t)cols > SIZE_MAX / sizeof(int)) {
        fprintf(stderr, "Matrix is too large.\n");
        return 1;
    }

    size_t total = (size_t)rows * (size_t)cols;
    int *matrix = malloc(total * sizeof(*matrix));
    if (matrix == NULL) {
        fprintf(stderr, "Unable to allocate memory for the matrix.\n");
        return 1;
    }

    for (size_t i = 0; i < total; i++) {
        if (scanf("%d", &matrix[i]) != 1) {
            fprintf(stderr, "Invalid matrix input.\n");
            free(matrix);
            return 1;
        }
    }

    printSpiral(matrix, rows, cols);
    free(matrix);
    return 0;
}
