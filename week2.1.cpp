#include <iostream>
#include <vector>
using namespace std;

int firstOccurrence(vector<int>& arr, int n, int key) {
    int low = 0, high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            result = mid;
            high = mid - 1;   // move left
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return result;
}

int lastOccurrence(vector<int>& arr, int n, int key) {
    int low = 0, high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            result = mid;
            low = mid + 1;   // move right
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int key;
        cin >> key;

        int first = firstOccurrence(arr, n, key);

        if (first == -1) {
            cout << "Key not present" << endl;
        } else {
            int last = lastOccurrence(arr, n, key);
            int count = last - first + 1;
            cout << key << "-" << count << endl;
        }
    }

    return 0;
}
