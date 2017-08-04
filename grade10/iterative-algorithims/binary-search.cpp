#include <iostream>
using namespace std;

// Adding prototypes of functions
void quickSort(int arr[], int left, int right);
int binarySearch (int arr[], int left, int right, int value);

int main()
{
    int array[20];
    int search;
    
    // Populating areas
    cout << "Please enter 20 values: " << endl;
    
    for (int i = 0; i < 20; i ++)
    {
        cout << "Enter Value " << i + 1 << ":";
        cin >> array[i];
    }
    
    quickSort (array, 0, 19); // Sorts array from least to greatest
    
    cout << "Please enter the value you would like to search for: ";
    cin >> search;
    
    int searchIndex = binarySearch (array, 0, 19, search); // Uses binary search to find specific value
    
    // Outputs index of value in array
    if (searchIndex >= 0)
    {
        cout << "The value of " << search << " is at index " << binarySearch (array, 0, 19, search) <<" in the array." << endl;
    }
    else
    {
        cout << "The value is not in the array." << endl;
    }
    
    return 0;
}

// Uses recursion to implement binary search
int binarySearch (int arr[], int left, int right, int value)
{
    int key = (left + right)/2;
    
    if (key < value)
    {
        binarySearch (arr, 0, key - 1, value);
    }
    else if (key > value)
    {
        binarySearch (arr, key + 1, right, value);
    }
    else if (key == value)
    {
        return key;
    }
    
    return -1;
}

// Quick sort algorithim (similar to binary)
void quickSort(int arr[], int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    
    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    
    /* recursion */
    if (left < j)
    {
        quickSort(arr, left, j);
    }
    if (i < right)
    {
        quickSort(arr, i, right);
    }
}
