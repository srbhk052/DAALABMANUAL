#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

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

        unordered_map<int, int> freq;

        // Step 1: Build frequency map
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }

        bool found = false;

        // Step 2: Check for valid pair
        for (int i = 0; i < n; i++) {
            int x = arr[i];
            int complement = key - x;

            // Reduce frequency temporarily to avoid using same element twice
            freq[x]--;

            if (freq[complement] > 0) {
                cout << x << " " << complement << endl;
                found = true;
                break;
            }

            // Restore frequency
            freq[x]++;
        }

        if (!found) {
            cout << "No Such Elements Exist" << endl;
        }
    }

    return 0;
}