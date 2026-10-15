#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int matrix[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    while (top < bottom && left < right) {
        int len = right - left;
        for (int i = 0; i < len; i++) {
            int temp = matrix[top][left + i];
            matrix[top][left + i] = matrix[bottom - i][left];
            matrix[bottom - i][left] = matrix[bottom][right - i];
            matrix[bottom][right - i] = matrix[top + i][right];
            matrix[top + i][right] = temp;
        }
        top++;
        bottom--;
        left++;
        right--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", matrix[i][j]);
            if (j < n - 1) {
                printf(" ");
            }}
        printf("\n");
    } return 0;
}