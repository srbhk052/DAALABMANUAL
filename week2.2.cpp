#include <iostream>
#include <vector>
using namespace std;
bool findThreeIndices(const vector<int>& arr, int n, int &iPos, int &jPos, int &kPos) {
    for (int k = n - 1; k >= 2; k--) {
        int i = 0;
        int j = k - 1;

        while (i < j) {
            int sum = arr[i] + arr[j];

            if (sum == arr[k]) {
                iPos = i;
                jPos = j;
                kPos = k;
                return true;
            } 
            else if (sum < arr[k]) {
                i++;
            } 
            else {
                j--;
            }
        }
    }
    return false;
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

        int iPos, jPos, kPos;

        if (findThreeIndices(arr, n, iPos, jPos, kPos)) {
            cout << iPos << " " << jPos << " " << kPos << endl;
        } else {
            cout << "No sequence found" << endl;
        }
    }

    return 0;
}
