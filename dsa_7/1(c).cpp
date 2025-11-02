// Q1(c). Implement Bubble Sort algorithm
#include <iostream>
using namespace std;

int main() {
    int a[] = {5, 1, 4, 2, 8};
    int n = 5;

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);

    cout << "Bubble Sort: ";
    for (int x : a) cout << x << " ";
}
