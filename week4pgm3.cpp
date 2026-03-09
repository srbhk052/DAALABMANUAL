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

        int k;
        cin >> k;

        sort(arr, arr+n);

        if(k > n)
            cout<<"not present"<<endl;
        else
            cout<<arr[k-1]<<endl;
    }

    return 0;
}