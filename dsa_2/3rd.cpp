#include <iostream>
using namespace std;

int findMissing(int arr[], int n) {
    int diff = (arr[n - 1] - arr[0]) / n;
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        int expected = arr[0] + mid * diff;
        if (arr[mid] == expected) l = mid + 1;
        else r = mid - 1;
    }
    return arr[0] + l * diff;
}

int main() {
    int arr[] = {2, 4, 6, 10, 12};
    int n = 5;
    cout << "Missing number is " << findMissing(arr, n) << endl;
    return 0;
}