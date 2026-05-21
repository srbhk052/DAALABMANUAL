#include <iostream>
#include <algorithm> // For sorting
using namespace std;
bool hasDuplicates(int arr[], int n) {
sort(arr, arr + n); // Sorting the array
for (int i = 1; i < n; i++) {
if (arr[i] == arr[i - 1])
return true;
}
return false;
}
// Driver function
int main() {
int T, n;
cin >> T;
while (T--) {
cin >> n;
int arr[n];
for (int i = 0; i < n; i++) cin >> arr[i];
cout << (hasDuplicates(arr, n) ? "YES" : "NO") << endl;
}
return 0;
} 