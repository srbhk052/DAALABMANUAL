#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

long long comparisons = 0;
long long swaps = 0;

// Partition using direct pivot (no swap to end)
int partitionDirect(vector<int> &arr, int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    int pivot = arr[pivotIndex];

    int i = low;
    int j = high;

    while (i <= j) {
        // Move i to the right
        while (arr[i] < pivot) {
            comparisons++;
            i++;
        }
        comparisons++;

        // Move j to the left
        while (arr[j] > pivot) {
            comparisons++;
            j--;
        }
        comparisons++;

        if (i <= j) {
            swap(arr[i], arr[j]);
            swaps++;
            i++;
            j--;
        }
    }

    return i;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int index = partitionDirect(arr, low, high);

        quickSort(arr, low, index - 1);
        quickSort(arr, index, high);
    }
}

int main() {
    srand(time(0));

    int T;
    cin >> T;

    vector<int> arr;

    while (T--) {
        int n;
        cin >> n;

        arr.clear();

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        comparisons = 0;
        swaps = 0;

        quickSort(arr, 0, n - 1);

        // Print sorted array
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << comparisons << endl;
        cout << swaps << endl;
    }

    return 0;
}
