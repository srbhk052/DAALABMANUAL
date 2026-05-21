#include <iostream>
#include <vector>
using namespace std;

void selectionSortCount(vector<int> &arr, long long &comparisons, long long &swaps) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            comparisons++;

            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps++;
        }
    }
}

int main() {
    int T;
    cin >> T;

    vector<int> arr;

    while (T--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        long long comparisons = 0;
        long long swaps = 0;

        selectionSortCount(arr, comparisons, swaps);

        // Print sorted array
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << comparisons << endl;
        cout << swaps << endl;

        // Clear vector after function call
        arr.clear();
    }

    return 0;
}
