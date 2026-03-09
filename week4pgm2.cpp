#include<iostream>
#include<cstdlib>
using namespace std;

int comparisons = 0;
int swaps = 0;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        comparisons++;

        if(arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }

    swap(arr[i+1], arr[high]);
    swaps++;

    return i+1;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int randomIndex = low + rand() % (high - low + 1);
        swap(arr[randomIndex], arr[high]);

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int arr[200];

        for(int i = 0; i < n; i++)
            cin >> arr[i];

        comparisons = 0;
        swaps = 0;

        quickSort(arr, 0, n-1);

        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << endl;

        cout << "comparisons = " << comparisons << endl;
        cout << "swaps = " << swaps << endl;
    }

    return 0;
}