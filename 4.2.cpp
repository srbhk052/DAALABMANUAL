#include <iostream>
#include <cstdlib> // for rand()
using namespace std;
int comparisons = 0, swaps = 0;
// Partition function
int partition(int arr[], int low, int high) {
int randomIdx = low + rand() % (high - low + 1);
swap(arr[randomIdx], arr[high]); // Swap random pivot with last element
swaps++;
int pivot = arr[high];
int i = low - 1;
for (int j = low; j < high; j++) {
comparisons++;
if (arr[j] < pivot) {
i++;
swap(arr[i], arr[j]);
swaps++;
}
}
swap(arr[i + 1], arr[high]);
swaps++;
return i + 1;
}
// Quick Sort function
void quickSort(int arr[], int low, int high) {
if (low < high) {
int pi = partition(arr, low, high);
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}int main() {
int T, n;
cin >> T;
while (T--) {
cin >> n;
int arr[n];
for (int i = 0; i < n; i++) cin >> arr[i];
comparisons = swaps = 0;
quickSort(arr, 0, n - 1);
for (int i = 0; i < n; i++) cout << arr[i] << " ";
cout << "\nComparisons = " << comparisons << "\n";
cout << "Swaps = " << swaps << "\n";
}
return 0;
}