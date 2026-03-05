#include<iostream>
using namespace std;
int main (){
    int n;
    cin>>n;
    int arr[100];
    for (int i =0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
     int comparisons=0;
     bool found= false ;

     for (int i =0;i<n;i++){
        comparisons++;
        if(key==arr[i]){
            found = true;
            break;
        }
     }
     if(found)
     cout<<"present"<<comparisons;
     else
     cout<<"not present"<<comparisons;
     return 0;
}