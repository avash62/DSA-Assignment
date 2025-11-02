// Q1(b). Implement Insertion Sort algorithm
#include <iostream>
using namespace std;

int main() {
    int a[] = {5, 2, 9, 1, 5, 6};
    int n = 6;

    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    cout << "Insertion Sort: ";
    for (int x : a) cout << x << " ";
}
