#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    unordered_map<int, int> freq;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    int duplicates = 0;

    for (auto it : freq) {
        if (it.second > 1) {
            duplicates += it.second - 1;
        }
    }

    cout << "Total number of duplicate elements: " << duplicates;

    return 0;
}
