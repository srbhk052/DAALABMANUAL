#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[299];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int key;
        cin>>key;
        int low=0,high=n-1;
        int first=-1,last=-1;
        //first occurence
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==key){
                first=mid;
                high=mid-1;
            }
            else if(arr[mid]<key){
                low=mid+1;}
                else
                high=mid-1;
                
            }
            // last occurence
            low=0;
            high=n-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(arr[mid]==key){
                    last=mid;
                    low=mid+1;
                }
                else if(arr[mid]<key)
                low=mid+1;
                else
                high=mid-1;
            }
            if(first==-1)
                cout<<"key not present"<<endl;
                else
                cout<<key<<" "<<last-first+1<<endl;
            }
            return 0;
        }

    