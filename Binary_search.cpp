#include<iostream>
using namespace std;

int binarySearch(int a[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] == target) {
            return mid;
        } else if (a[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int size, target;
    cout << "Enter array size: ";
    cin >> size;

    int arr[size];
    cout << "Enter array elements (in sorted order): ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Enter target element: ";
    cin >> target;

    if (binarySearch(arr, size, target) == -1) {
        cout << "Not found";
    } else {
        cout << "Element Found at index "<<binarySearch(arr, size, target);
    }

    return 0;
}
