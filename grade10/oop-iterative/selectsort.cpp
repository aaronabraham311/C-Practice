// Including libraries and header files
#include "selectsort.hpp"
#include <iostream>

using namespace std;

// Entering array
void selectsort:: entersarray()
{
    // Getting size of array and sanitizing
    do
    {
        cout << "Please enter the size of the select sort array: ";
        cin >> size;
    } while (size <= 0);
    
    // Asking user for array values
    cout << "Please enter numbers that you would like to sort into the array: " << endl;
    
    for (i = 0; i < size; i ++)
    {
        cin >> array[i];
    }
    
    return;
}

// Sorting array using select sort
void selectsort:: sortselect()
{
    int minimumValue;
    
    for (i = 0; i < size - 1; i ++)
    {
        minimumValue = i;
        
        for (j = i + 1; j < size; j ++)
        {
            if (array[j] < array[minimumValue])
            {
                minimumValue = j;
            }
        }
        
        if (minimumValue != i)
        {
            temp = array[i];
            array[i] = array[minimumValue];
            array[minimumValue] = temp;
        }
    }
    
    return;
}

// Displaying array
void selectsort:: displaysortselect()
{
    cout << "Sorted array: " << endl;
    
    for (i = 0; i < size; i ++) // Displaying each element of array
    {
        cout << array[i] << " ";
    }
    
    cout << endl;
    
    return;
}
