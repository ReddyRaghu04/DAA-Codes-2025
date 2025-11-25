#include <iostream>
using namespace std;
void bubblesort(int arr[],int size){
    int flag=0;
    for(int i=0;i<size-1;i++){
        flag=0;
        for(int j=1;j<size-i;j++){
            if(arr[j]<arr[j-1]){
                int temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
                flag=1;
            }
        }
         if(flag==0)break;
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
};
int main() {
   int size;
   cout<<"Enter array size:";
   cin>>size;
   int arr[size];
   cout<<"Enter array Elements:\n";
   for(int i=0;i<size;i++){
    cin>>arr[i];
   }
   bubblesort(arr,size);
    return 0;
}
