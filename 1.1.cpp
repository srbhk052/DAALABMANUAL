#include <iostream>
#include <vector>
using namespace std;

// Linear search function
bool linearSearch(const vector<int>& arr, int key, int& comparisons) {
    comparisons = 0;

    for (int value : arr) {
        comparisons++;
        if (value == key) {
            return true;
        }
    }
    return false;
}

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int key;
        cin >> key;

        int comparisons = 0;
        bool isPresent = linearSearch(arr, key, comparisons);

        if (isPresent) {
            cout << "Present " << comparisons << endl;
        } else {
            cout << "Not Present " << comparisons << endl;
        }
    }

    return 0;
}