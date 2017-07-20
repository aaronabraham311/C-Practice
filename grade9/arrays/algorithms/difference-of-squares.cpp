#include <iostream>
#include <cmath>

using namespace std;

// Finds sum of difference of squares of array
float arraySquareSum (float array1[], float array2[], int arraySize);

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
    
    // Outputting sum of squares of difference
    cout << "The square of the differences of the corresponding elements of the array is: " << arraySquareSum (userArray1, userArray2, userSize) << endl;
    
    return 0;
}

float arraySquareSum (float array1[], float array2[], int arraySize)
{
    float arraySum;
    
    // Makes a loop that finds the sum of squares of differences
    for (int index = 0; index < arraySize; index++)
        arraySum += pow((array1[index] - array2[index]), 2);
    
    return arraySum;
}
