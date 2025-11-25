#include <iostream>
using namespace std;
void insertionsort(int arr[],int size){
    for(int i=1;i<size;i++){
        for(int j=i;j>0;j--){
            if(arr[j-1]>arr[j]){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
    cout<<"Sorted array\n";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
};
int main() {
   int size;
   cout<<"Enter array size:";
   cin>>size;
   int arr[size];
   cout<<"Enter array Elements:";
   for(int i=0;i<size;i++){
    cin>>arr[i];
   }
   insertionsort(arr,size);
    return 0;
}
