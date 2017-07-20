#include <iostream>
using namespace std;

// Establishing prototype of dot product function
float dotProduct (float array1[], float array2[], int size);

int main()
{
    // Declaring size variable
    int arraySize;
    
    cout << "Please enter the array size: ";
    cin >> arraySize;
    
    // Making two arrays with same size
    float userArray1[arraySize], userArray2[arraySize];
    
    // Entering all elements for the first array
    cout << "Please enter the elements of the first array: ";
    
    for (int index = 0; index < arraySize; index ++)
        cin >> userArray1[index];
    
    // Entering all elements for the second array
    cout << "Please enter the element of the second array: ";
    
    for (int index = 0; index < arraySize; index ++)
        cin >> userArray2[index];
    
    // Outputting dot product for two arrays using function
    cout << "The dot product of these two arrays is: " << dotProduct(userArray1, userArray2, arraySize) << endl;
    
    return 0;
}

float dotProduct (float array1[], float array2[], int size)
{
    float dotProduct = 0;
    
    // Adding product of same indices of both arrays to the dot product
    for (int index = 0; index < size; index++)
        dotProduct += array1[index] * array2[index];
    
    return dotProduct;
}
