#include <iostream>

using namespace std;

void quickSort(int arr[], int left, int right); // Function that sorts array

int main()
{
    int array[10];
    
    cout << "Please input 10 values into the array: ";
    
    for (int i = 0; i < 10; i ++) // Populates array with 10 values
    {
        cin >> array[i];
    }
    
    quickSort(array, 0, 9); // Sorts array
    
    cout << "This is your sorted array: " << endl;
    
    for (int i = 0; i < 10; i ++) // Outputs array
    {
        cout << array[i] << endl;
    }
    
    return 0;
}

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
