#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& a, int l, int m, int r,
           long long &comparisons, long long &inversions) {

    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        comparisons++;

        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        } 
        else {
            a[k++] = R[j++];
            inversions += (n1 - i);
        }
    }

    while (i < n1)
        a[k++] = L[i++];

    while (j < n2)
        a[k++] = R[j++];
}

void mergeSort(vector<int>& a, int l, int r,
               long long &comparisons, long long &inversions) {

    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(a, l, m, comparisons, inversions);
        mergeSort(a, m + 1, r, comparisons, inversions);
        merge(a, l, m, r, comparisons, inversions);
    }
}

int main() {
    int T;
    cin >> T;

    vector<int> a;

    while (T--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }

        long long comparisons = 0;
        long long inversions = 0;

        mergeSort(a, 0, n - 1, comparisons, inversions);

        // Sorted array
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;

        // Comparisons
        cout << comparisons << endl;

        // Inversions
        cout << inversions << endl;

        a.clear();   // clear after work is done
    }

    return 0;
}