#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[100][100];
    int result[10000];
    int k = 0;

    // Input matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // Left to right
        for (int j = left; j <= right; j++) {
            result[k++] = matrix[top][j];
        }
        top++;

        // Top to bottom
        for (int i = top; i <= bottom; i++) {
            result[k++] = matrix[i][right];
        }
        right--;

        // Right to left
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                result[k++] = matrix[bottom][j];
            }
            bottom--;
        }

        // Bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[k++] = matrix[i][left];
            }
            left++;
        }
    }

    // Print spiral order
    printf("[");
    for (int i = 0; i < k; i++) {
        printf("%d", result[i]);
        if (i < k - 1) {
            printf(",");
        }
    }
    printf("]\n");

    return 0;
}