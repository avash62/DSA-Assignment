#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = 6;
    int key = 40;
    int idx = binarySearch(arr, n, key);
    if (idx != -1) cout << "Found at index " << idx << endl;
    else cout << "Not Found" << endl;
    return 0;
}