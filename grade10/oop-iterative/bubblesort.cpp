// Including libraries and header file
#include <iostream>
#include "bubblesort.hpp"

using namespace std;

// Entering array
void bubblesort:: enterbarray()
{
    // Getting size of array and sanitizing
    do
    {
        cout << "Please enter the size of the bubble sort array: ";
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

// Sorting array using bubble sort
void bubblesort:: sortbubble()
{
    for (i = 0; i < size; i ++)
    {
        for (j = 0; j < size - 1; j ++)
        {
            if (array[j + 1] < array[j])
            {
                int temporary = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temporary;
            }
        }
    }
    
    return;
}

// Displaying array
void bubblesort:: displaysortbubble()
{
    cout << "Sorted array: " << endl;
    
    for (i = 0; i < size; i ++) // Displaying each element of array
    {
        cout << array[i] << " ";
    }
    
    cout << endl;
    
    return;
}

