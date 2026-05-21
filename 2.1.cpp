#include <iostream>
using namespace std;
// Function to find the first occurrence of the key
int firstOccurrence(int arr[], int n, int key) {
int low = 0, high = n - 1, result = -1;
while (low <= high) {
int mid = low + (high - low) / 2;
if (arr[mid] == key) {
result = mid;
high = mid - 1; // Search in the left half
} else if (arr[mid] < key) {
low = mid + 1;
} else {
high = mid - 1;
}
}
return result;
}
// Function to find the last occurrence of the key
int lastOccurrence(int arr[], int n, int key) {
int low = 0, high = n - 1, result = -1;
while (low <= high) {
int mid = low + (high - low) / 2;
if (arr[mid] == key) {
result = mid;
low = mid + 1; // Search in the right half
} else if (arr[mid] < key) {
low = mid + 1;
} else {
high = mid - 1;
}
}
return result;
}
int main() {
int T;
cin >> T; // Number of test cases
while (T--) {
int n, key;
cin >> n;
int arr[n];
for (int i = 0; i < n; i++) cin >> arr[i];
cin >> key;
int first = firstOccurrence(arr, n, key);
int last = lastOccurrence(arr, n, key);
if (first == -1) {
cout << "Key not present" << endl;
} else {
cout << key << " - " << (last - first + 1) << endl;
}
}
return 0;
}