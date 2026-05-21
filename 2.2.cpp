#include <iostream>
using namespace std;
// Function to perform binary search
bool binarySearch(int arr[], int low, int high, int key) {
while (low <= high) {
int mid = low + (high - low) / 2;
if (arr[mid] == key)
return true;
else if (arr[mid] < key)
low = mid + 1;
else
high = mid - 1;
}
return false;
}
int main() {
int T;
cin >> T;
while (T--) {
int n;
cin >> n;
int arr[n];
for (int i = 0; i < n; i++) cin >> arr[i];
bool found = false;
for (int i = 0; i < n - 1; i++) {
for (int j = i + 1; j < n; j++) {
int sum = arr[i] + arr[j];
if (binarySearch(arr, j + 1, n - 1, sum)) {
cout << i + 1 << ", " << j + 1 << ", " << (lower_bound(arr + j + 1, arr + n, sum) - arr + 1) <<
endl;
found = true;
break;
}}
if (found) break;
}
if (!found) cout << "No sequence found." << endl;
}
return 0;
}