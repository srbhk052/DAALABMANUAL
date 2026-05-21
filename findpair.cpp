#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void findPair(const vector<int>& arr, int key)
{
    unordered_map<int, bool> hash;

    bool found = false;

    for (int i = 0; i < arr.size(); i++)
    {
        int needed = key - arr[i];

        // check if needed element exists
        if (hash.find(needed) != hash.end())
        {
            cout << needed << " " << arr[i] << endl;
            found = true;
            break;
        }

        // store current element
        hash[arr[i]] = true;
    }

    if (!found)
        cout << "No Such Elements Exist" << endl;

    // clear hash map
    hash.clear();
}

int main()
{
    int T;
    cin >> T;

    vector<int> arr;   // declared outside loop

    while (T--)
    {
        int n;
        cin >> n;

        arr.resize(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int key;
        cin >> key;

        findPair(arr, key);

        // clear vector after test case
        arr.clear();
    }

    return 0;
}