// 5) Sum of every row and column in a 2D array

#include <stdio.h>
int main() {
    int a[10][10], n, m, i, j;
    scanf("%d %d", &n, &m);
    if (n <= 0 || m <= 0 || n > 10 || m > 10) {
        printf("Invalid matrix size\n");
        return 0;
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    for (i = 0; i < n; i++) {
        int sum = 0;
        for (j = 0; j < m; j++)
            sum += a[i][j];
        printf("Sum of row %d = %d\n", i + 1, sum);
    }
    for (j = 0; j < m; j++) {
        int sum = 0;
        for (i = 0; i < n; i++)
            sum += a[i][j];
        printf("Sum of column %d = %d\n", j + 1, sum);
    }
    return 0;
}