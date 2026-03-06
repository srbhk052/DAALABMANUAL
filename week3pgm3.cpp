#include<iostream>
#include<algorithm>
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

        sort(arr, arr+n);

        bool duplicate = false;

        for(int i=0;i<n-1;i++)
        {
            if(arr[i] == arr[i+1])
            {
                duplicate = true;
                break;
            }
        }

        if(duplicate)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}