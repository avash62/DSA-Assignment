#include <iostream>
using namespace std;

int countDistinct(int arr[], int n) {
    int maxVal = arr[0];
    for (int i=1;i<n;i++) if (arr[i] > maxVal) maxVal = arr[i];

    int *freq = new int[maxVal+1];
    for (int i=0;i<=maxVal;i++) freq[i] = 0;

    for (int i=0;i<n;i++) freq[arr[i]]++;

    int distinct=0;
    for (int i=0;i<=maxVal;i++) if (freq[i] > 0) distinct++;

    delete [] freq;
    return distinct;
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4};
    int n = 6;
    cout << "Distinct elements = " << countDistinct(arr, n) << endl;
    return 0;
}