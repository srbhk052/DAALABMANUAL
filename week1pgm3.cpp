#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[200];
    int i;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cin>>key;
    int comparisons=0;
    //jump search
    for(i=0;i<n;i=i+2){
        comparisons++;
        if(arr[i]>=key){
            break;
        }
    }
    //linear search
    int start=i-2;
    if(start<0){
        start=0;
    }
    bool found=false;
    for(int j=start;j<=i && j<n;j++){
        comparisons++;
        if(arr[j]==key){
            found=true;
            break;
        }
    }
    
if(found){
    cout<<"present"<<comparisons;}
 else
 cout<<"not presnt"<<comparisons;
 return 0;
}

    
