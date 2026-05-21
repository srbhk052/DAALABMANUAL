#include <iostream>
#include <vector>
using namespace std;

void insertionSortCount(vector<int> &arr, long long &comparisons, long long &shifts) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            comparisons++;

            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                shifts++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
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
        long long shifts = 0;

        insertionSortCount(arr, comparisons, shifts);

        // Print sorted array
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << comparisons << endl;
        cout << shifts << endl;

        // Clear vector after function call
        arr.clear();
    }

    return 0;
}