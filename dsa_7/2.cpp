#include <iostream>
using namespace std;

int main() {
    int a[] = {5, 2, 9, 1, 6, 3};
    int n = 6;

    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int min = i, max = i;
        for (int k = i; k <= j; k++) {
            if (a[k] < a[min]) min = k;
            if (a[k] > a[max]) max = k;
        }
        swap(a[i], a[min]);
        if (max == i) max = min;  // adjust if swapped
        swap(a[j], a[max]);
    }

    cout << "Improved Selection Sort: ";
    for (int x : a) cout << x << " ";
}
