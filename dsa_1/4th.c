// 4a) Reverse elements of an array
#include <stdio.h>
int main() {
    int arr[100], n, i, temp;
    scanf("%d", &n);
    if (n <= 0 || n > 100) 
    return 0;
    for (i = 0; i < n; i++) 
    scanf("%d", &arr[i]);
    for (i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}


// 4b) Matrix multiplication
#include <stdio.h>

int main() {
	int a[10][10], b[10][10], c[10][10], n, m, p, q, i, j, k;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) 
  for (j = 0; j < m; j++) 
      scanf("%d", &a[i][j]);
	    scanf("%d %d", &p, &q);
	for (i = 0; i < p; i++) 
  for (j = 0; j < q; j++) 
  scanf("%d", &b[i][j]);
	if (m != p) 
  return 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < q; j++) {
			c[i][j] = 0;
			for (k = 0; k < m; k++) 
     c[i][j] += a[i][k] * b[k][j];
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < q; j++) 
    printf("%d ", c[i][j]);
		printf("\n");
	}
	return 0;
}


// 4c) Transpose of a matrix
#include <stdio.h>
int main() {
    int a[10][10], t[10][10];
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            t[j][i] = a[i][j];

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", t[i][j]);
        printf("\n");
    }
    return 0;
}