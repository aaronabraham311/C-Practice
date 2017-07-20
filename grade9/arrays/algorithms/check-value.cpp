#include <iostream>

using namespace std;

// Checks if value is part of array
int arrayCheck (float array[], int arraySize, float value);

int main()
{
    // Declaring variables of array size and value
    int userSize;
    float userValue;
    
    // Getting size of array
    cout << "Please enter the size of the array: ";
    cin >> userSize;
    
    // Establishing array and getting elements
    float userArray[userSize];
    
    cout << "Please enter the elements of the array: ";
    for (int index = 0; index < userSize; index ++)
        cin >> userArray[index];
    
    // Getting value
    cout << "Please enter a desired value: ";
    cin >> userValue;
    
    cout << "The index of your desired value is: " << arrayCheck(userArray, userSize, userValue) << endl;
    
    return 0;
}

int arrayCheck (float array[], int arraySize, float value)
{
    // Makes a loop that checks all values and sees if it corresponds with user's value
    for (int index = 0; index < arraySize; index++)
    {
        if (array[index] == value)
            return index;
    }
    return -1;
}
