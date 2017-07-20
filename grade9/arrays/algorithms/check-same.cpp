#include <iostream>

using namespace std;

// Finds average of array
bool arrayTest (float array1[], float array2[], int arraySize);

int main()
{
    // Declaring variables of array size and value
    int userSize;
    
    // Getting size of array
    cout << "Please enter the size of the array: ";
    cin >> userSize;
    
    // Establishing arrays and getting elements
    float userArray1[userSize];
    
    cout << "Please enter the elements of the first array: ";
    for (int index = 0; index < userSize; index ++)
        cin >> userArray1[index];
    
    float userArray2[userSize];
    
    cout << "Please enter the elements of the second array: ";
    for (int index = 0; index < userSize; index ++)
        cin >> userArray2[index];
    
    // Outputting true/false if arrays are equal
    cout << arrayTest (userArray1, userArray2, userSize) << endl;
    
    return 0;
}

bool arrayTest (float array1[], float array2[], int arraySize)
{
    float arraySum;
    
    // Makes a loop that finds the sum of all elements of the array
    for (int index = 0; index < arraySize; index++)
    {
        if (array1[index] == array2[index])
            arraySum ++;
    }
    
    if (arraySum == arraySize)
        return true;
    
    return false;
}
