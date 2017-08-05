#include <iostream>

using namespace std;

void selectiveSort (int array[], int size);
void inputArray (int array[], int size);
void displayArray (int array[], int size);

int main()
{
    int array[5];
    
    inputArray (array, 5);
    selectiveSort(array, 5);
    displayArray (array, 5);
    
    return 0;
}

void inputArray (int array[], int size)
{
    cout << "Please input 5 values for the array: " << endl;
    
    for (int i = 0; i < size; i ++)
    {
        cin >> array[i];
    }
    
    return;
}

void displayArray (int array[], int size)
{
    cout << "The values of the array are: " << endl;
    
    for (int i = 0; i < size; i ++)
    {
        cout << array[i] << " ";
    }
    
    cout << endl;
    
    return;
}

void selectiveSort (int array[], int size)
{
    int minimumValue, temporary, i , j;
    
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
            temporary = array[i];
            array[i] = array[minimumValue];
            array[minimumValue] = temporary;
        }
    }
}
