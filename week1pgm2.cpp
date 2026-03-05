#include<iostream>
using namespace std;
int main (){
    int n;
    cin>>n;
    int arr[200];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key; 
    cin>>key;

    int comparisons=0;
    bool found=false;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        comparisons++;

        if(key==arr[mid]){
            found = true;
            break;
        }
        else if(key<arr[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }

    }
    if(found)
    cout<<"present"<<comparisons;
    else
    cout<<"not present"<<comparisons;
    return 0;

}