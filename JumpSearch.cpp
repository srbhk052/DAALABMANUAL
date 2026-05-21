#include <iostream>
#include <vector>
#include <cmath> // for sqrt
using namespace std;

// Jump Search Function
// TC: O(sqrt(n))
// SC: O(1)
bool jumpSearch(const vector<int>& arr, int key, int& comparisons, int& position) {
    int n = arr.size();
    int step = sqrt(n);  // jump size
    int prev = 0;

    comparisons = 0;

    // Jumping in blocks
    while (arr[min(step, n) - 1] < key) {
        comparisons++;
        prev = step;
        step += sqrt(n);
        if (prev >= n)  // key not present
            return false;
    }

    // Linear search in the block
    for (int i = prev; i < min(step, n); i++) {
        comparisons++;
        if (arr[i] == key) {
            position = i + 1; // 1-based index
            return true;
        }
    }

    return false;
}

int main() {
    int testCases;
    cout << "No of test cases: ";
    cin >> testCases;

    while (testCases--) {
        int n;
        cout << "No of elements: ";
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int key;
        cout << "Element to search: ";
        cin >> key;

        int comparisons = 0;
        int position = -1;

        bool found = jumpSearch(arr, key, comparisons, position);

        if (found)
            cout << "Present " << position << endl;
        else
            cout << "Not Present " << comparisons << endl;

        // Time Complexity: O(sqrt(n))
        // Space Complexity: O(1)
    }

    return 0;
}