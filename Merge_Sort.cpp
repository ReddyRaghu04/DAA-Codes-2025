#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int s1 = mid - left + 1;    
    int s2 = right - mid;       

    int larr[s1], rarr[s2];

    for (int i = 0; i < s1; i++)
        larr[i] = arr[left + i];

    for (int i = 0; i < s2; i++)
        rarr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < s1 && j < s2)
    {
        if (larr[i] <= rarr[j])
            arr[k++] = larr[i++];
        else
            arr[k++] = rarr[j++];
    }

    while (i < s1)
        arr[k++] = larr[i++];

    while (j < s2)
        arr[k++] = rarr[j++];
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);   
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int arr[size];
    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];   

    cout << "Original Array: ";
    printArray(arr, size);

    merge_sort(arr, 0, size - 1);

    cout << "Sorted Array: ";
    printArray(arr, size);

    return 0;
}
