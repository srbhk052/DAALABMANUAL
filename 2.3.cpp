#include <iostream>
#include <algorithm>
using namespace std;
int countPairsWithDiff(int arr[], int n, int K) {
sort(arr, arr + n); // Step 1: Sort the array (O(n log n))
int count = 0;
int i = 0, j = 1;
// Step 2: Two-pointer technique
while (j < n) {
int diff = arr[j] - arr[i];
if (diff == K) {
count++;
i++;
j++;
} else if (diff < K) {
j++;
} else {
i++;
}
}
return count;
}
int main() {
int T;
cin >> T;
while (T--) {
int n, K;
cin >> n;
int arr[n];
for (int i = 0; i < n; i++) cin >> arr[i];
cin >> K;
cout << countPairsWithDiff(arr, n, K) << endl;
}
return 0;
}