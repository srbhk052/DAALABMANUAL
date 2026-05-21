#include <iostream>
#include <cstdlib>
using namespace std;
// Partition function
int partition(int arr[], int low, int high) {
int pivot = arr[high];
int i = low - 1;
for (int j = low; j < high; j++) {
if (arr[j] < pivot) {
i++;
swap(arr[i], arr[j]);
}
}
swap(arr[i + 1], arr[high]);
return i + 1;
}
// QuickSelect function to find Kth smallest element
int quickSelect(int arr[], int low, int high, int k) {
if (low <= high) {
int pi = partition(arr, low, high);
if (pi == k - 1) return arr[pi]; // Kth smallest element found
else if (pi > k - 1) return quickSelect(arr, low, pi - 1, k);
else return quickSelect(arr, pi + 1, high, k);
}
return -1; // If k is out of range
}
int main() {
int T, n, k;
cin >> T;
while (T--) {
cin >> n;
int arr[n];
for (int i = 0; i < n; i++) cin >> arr[i];
cin >> k;
if (k > 0 && k <= n) {
cout << quickSelect(arr, 0, n - 1, k) << "\n";
} else {
cout << "Not present\n";
}
}
return 0;
}