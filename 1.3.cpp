#include <iostream>
#include <cmath>
using namespace std;
void jumpSearch(int arr[], int n, int key) {
int step = sqrt(n), prev = 0, comparisons = 0;
while (prev < n && arr[min(step, n) - 1] < key) {
comparisons++;
prev = step;
step += sqrt(n);
if (prev >= n) {
cout << "Not Present " << comparisons << endl;
return;
}
}
// Perform linear search in the identified block
while (prev < n && arr[prev] <= key) {
comparisons++;
if (arr[prev] == key) {
cout << "Present " << comparisons << endl;
return;
}
prev++;
}
cout << "Not Present " << comparisons << endl;
}int main() {
int T;
cin >> T;
while (T--) {
int n, key;
cin >> n;
int arr[n];
for (int i = 0; i < n; i++)
cin >> arr[i];
cin >> key;
jumpSearch(arr, n, key);
}
return 0;
}