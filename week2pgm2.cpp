#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int arr[1000];

        for(int i=0;i<n;i++)
            cin>>arr[i];

        bool found=false;

        for(int k=n-1;k>=2;k--){

            int i=0;
            int j=k-1;

            while(i<j){

                if(arr[i] + arr[j] == arr[k]){
                    cout<<i<<" "<<j<<" "<<k<<endl;
                    found=true;
                    break;
                }

                else if(arr[i] + arr[j] < arr[k])
                    i++;

                else
                    j--;
            }

            if(found)
                break;
        }

        if(!found)
            cout<<"No sequence found"<<endl;
    }

    return 0;
}