#include "quicksort.hpp"
#include <iostream>

using namespace std;

// Entering array
void quicksort:: enterqarray()
{
    
    // Asking user for array values
    cout << "Please enter 10 numbers that you would like to sort into the array: " << endl;
    
    for (i = 0; i < 10; i ++)
    {
        cin >> array[i];
    }
    
    sortquick (0, 9);
    
    return;
}

void quicksort:: sortquick(int left, int right) // PUT PARAMETERS
{
    int pivotValue = (left + right) / 2;
    pivot = array[pivotValue];
    
    while (i <= j)
    {
        while (array[i] < pivot)
        {
            i ++;
        }
        while (array[j] > pivot)
        {
            j --;
        }
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            
            i ++;
            j --;
        }
    }
    
    if (left < i)
    {
        sortquick(left, j);
    }
    if (i < right)
    {
        sortquick(i, right);
    }
}

void quicksort:: displaysortquick()
{
    cout << "Sorted array: " << endl;
    
    for (i = 0; i < size; i ++) // Displaying each element of array
    {
        cout << array[i] << " ";
    }
    
    cout << endl;
    
    return ;
}
