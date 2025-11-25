#include<iostream>
using namespace std;
void linearsearch(int a[],int size, int target){
    int index=-1;
    for(int i = 0;i<size;i++){
        if(a[i] == target){
            index=i;
            break;
        }
    }
    if(index==-1){
        cout<<"Target element is not found in the given array";
    }
    else{
        cout<<"Target element is found at index "<<index;
    }
}

int main(){
    int size,target;
    cout<<"Enter array size:";
    cin>>size;
    int arr[size];
    cout<<"Enter array Elements:";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Enter target Element:";
    cin>>target;
    linearsearch(arr, size, target);
        
    return 0;
}
