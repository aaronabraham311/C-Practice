// Including libraries and header file
#include "insertsort.hpp"
#include <iostream>

using namespace std;

// Entering array
void insertsort:: enteriarray()
{
    // Getting size of array and sanitizing
    do
    {
        cout << "Please enter the size of the insert sort array: ";
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

// Sorting array using insert sort
void insertsort:: sortinsert()
{
    for(i = 1; i < size; i++)
    {
        temp = array[i];
        j = i - 1;
        
        while((temp < array[j]) && (j >= 0))
        {
            array[j+1] = array[j];
            j = j-1;
        }
        
        array[j+1]=temp;
    }
    
    return;
}

// Displaying array
void insertsort:: displaysortinsert()
{
    cout << "Sorted array: " << endl;
    
    for (i = 0; i < size; i ++) // Displaying each element of array
    {
        cout << array[i] << " ";
    }
    
    cout << endl;
    
    return;
}
