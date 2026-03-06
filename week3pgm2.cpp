#include<iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int arr[200];

        for(int i=0;i<n;i++)
            cin >> arr[i];

        int comparisons = 0;
        int swaps = 0;

        for(int i=0;i<n-1;i++)
        {
            int min = i;

            for(int j=i+1;j<n;j++)
            {
                comparisons++;

                if(arr[j] < arr[min])
                {
                    min = j;
                }
            }

            if(min != i)
            {
                swap(arr[i], arr[min]);
                swaps++;
            }
        }

        for(int i=0;i<n;i++)
            cout << arr[i] << " ";

        cout << endl;

        cout << "comparisons = " << comparisons << endl;
        cout << "swaps = " << swaps << endl;
    }

    return 0;
}