#include <iostream>

using namespace std;

// Finds average of array
float arrayMean (float array[], int arraySize);

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
    
    // Outputting average of array
    cout << "The mean of your array is: " << arrayMean (userArray, userSize) << endl;
    
    return 0;
}

float arrayMean (float array[], int arraySize)
{
    float arraySum;
    
    // Makes a loop that finds the sum of all elements of the array
    for (int index = 0; index < arraySize; index++)
        arraySum += array[index];
    
    // Returns average
    return arraySum / arraySize;
}
