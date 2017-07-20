#include <iostream>
using namespace std;

// Prototyping two functions, which make the array left justified
void arrayReOrg (float array[], int arraySize);
int zeroCounter (float array[], int arraySize);

int main()
{
    int userSize;
    
    // Getting array size
    cout << "Please enter the array size: ";
    cin >> userSize;
    
    // Establishing array and elements
    float userArray[userSize];
    
    cout << "Please enter the elements of the array: ";
    
    for (int index = 0; index < userSize; index ++)
        cin >> userArray[index];
    
    // Reorganizing array
    arrayReOrg (userArray, userSize);
    
    // Outputting array
    cout << "*******************************************" << endl << "Outputting elements of array: " << endl;
    
    for (int index = 0; index < userSize; index ++)
        cout << userArray[index] << endl;;
    
    return 0;
}

void arrayReOrg (float array[], int arraySize)
{
    int zeroCount = zeroCounter (array, arraySize); // Making zero counter
    float prevValue1, prevValue2;
    int currentZeroCount;
    
    do
    {
        currentZeroCount = 0; // Establishing zero counter inside while loops
        
        // Finding how many zeros are in last indices of index and updating loop's zero counter
        for (int index = arraySize - zeroCount; index < arraySize; index ++)
        {
            if ( array[index] == 0)
                currentZeroCount ++;
        }
        
        // Updating array
        for (int index = 1; index < arraySize; index ++)
        {
            // Storing current array values for substitution
            prevValue1 = array[index - 1];
            prevValue2 = array[index];
            
            // Swapping two elements if first element is 0 and second element is not zero based on stored array values
            if ( (prevValue1 == 0) && (prevValue2 != 0))
            {
                array[index - 1] = prevValue2;
                array[index] = prevValue1;
            }
        }
    } while (currentZeroCount != zeroCount); // Exiting loop if correct last elements are zeroes
}

int zeroCounter (float array[], int arraySize)
{
    int zeroCount = 0;
    
    // Updates zeroCount every time zero is in array
    for (int index = 0; index < arraySize; index++)
    {
        if (array[index] == 0)
            zeroCount ++;
    }
    
    // Returning zero counter
    return zeroCount;
}
