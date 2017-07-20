#include <iostream>

using namespace std;

// Finds maximum value of array
float arrayMax (float array[], int arraySize);

int main()
{
    // Declaring variables of array size and value
    int userSize;
    
    // Getting size of array
    cout << "Please enter the size of the array: ";
    cin >> userSize;
    
    // Establishing array and getting elements
    float userArray[userSize];
    
    cout << "Please enter the elements of the array: ";
    for (int index = 0; index < userSize; index ++)
        cin >> userArray[index];
    
    // Outputting maximum value of array
    cout << "The maximum value of your array is: " << arrayMax (userArray, userSize) << endl;
    
    return 0;
}

float arrayMax (float array[], int arraySize)
{
    // Initializing arrayMax variable as first element of array
    float arrayMax = array[0];
    
    // Makes a loop that finds the maximum element of all elements of the array
    for (int index = 1; index < arraySize; index++)
    {
        if (arrayMax < array[index])
            arrayMax = array[index];
    }
    
    // Returns average
    return arrayMax;
}
