#include <iostream>
using namespace std;
void binarySearch(int arr[], int n, int key) {
int low = 0, high = n - 1, comparisons = 0;
while (low <= high) {
int mid = low + (high - low) / 2;
comparisons++; // Count comparisons
if (arr[mid] == key) {
cout << "Present " << comparisons << endl;
return;
}
else if (arr[mid] > key)
high = mid - 1;
else
low = mid + 1;
}
cout << "Not Present " << comparisons << endl;
}
int main() {
int T;
cin >> T;
while (T--) {
int n, key;
cin >> n;
int arr[n];
for (int i = 0; i < n; i++)
cin >> arr[i];
cin >> key;
binarySearch(arr, n, key);
}
return 0;
}