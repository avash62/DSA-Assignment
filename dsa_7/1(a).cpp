// Q1(a). Implement Selection Sort algorithm
#include <iostream>
using namespace std;

int main() {
    int a[] = {64, 25, 12, 22, 11};
    int n = 5;

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min]) min = j;
        swap(a[i], a[min]);
    }

    cout << "Selection Sort: ";
    for (int x : a) cout << x << " ";
}
