// 1) Menu-driven program for array operations


#include <stdio.h>
int main() {
    int n = 0, arr[100], val, pos, choice, i, found, search;

    while (1) {
        printf("\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter number of elements: ");
            scanf("%d", &n);
            printf("Enter elements ");
            for (i = 0; i < n; i++) 
                scanf("%d", &arr[i]);

        } else if (choice == 2) {
            printf("Array: ");
            for (i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n");

        } else if (choice == 3) {
            printf("Enter position and value: ");
            scanf("%d %d", &pos, &val);

            if (pos < 1 || pos > n+1) {
                printf("Invalid position\n");
            } else {
                for (i = n; i >= pos; i--) 
                    arr[i] = arr[i-1];
                arr[pos] = val;
                n++;
            }

        } else if (choice == 4) {
            printf("Enter position to delete: ");
            scanf("%d", &pos);

            if (pos < 1 || pos > n) {
                printf("Invalid position\n");
            } else {
                for (i = pos; i < n-1; i++) 
                    arr[i] = arr[i+1];
                n--;
            }

        } else if (choice == 5) {
            printf("Enter element to search: ");
            scanf("%d", &search);

            found = 0;
            for (i = 0; i < n; i++) {
                if (arr[i] == search) {
                    found = 1;
                    break;
                }
            }
            if (found) 
                printf("Found at position %d\n", i+1);
            else 
                printf("Not Found\n");

        } else if (choice == 6) {
            break;
        } 
    }
    return 0;
}