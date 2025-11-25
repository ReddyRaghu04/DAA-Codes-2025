#include<iostream>
using namespace std;

void countingSort(int arr[], int size) {
    int max = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    int count[max + 1] = {0};

    for(int i = 0; i < size; i++) {
        count[arr[i]]++;
    }


    int index = 0;
    for(int i = 0; i <= max; i++) {
        while(count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }


    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int size;
    cout << "Enter the size of array:";
    cin >> size;
    int arr[size];
    cout << "Enter array elements:";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    countingSort(arr, size);
    return 0;
}
