#include <iostream>
using namespace std;

int main()
{
    int array[5];
    
    cout << "Please enter 5 elements for the array: " << endl;
    
    for (int i = 0; i < 5; i ++)
    {
        cin >> array[i];
    }
    
    for (int i = 0; i < 5; i ++)
    {
        for (int ii = 0; ii < 4; ii ++)
        {
            if (array[ii + 1] < array[ii])
            {
                int temporary = array[ii];
                array[ii] = array[ii + 1];
                array[ii + 1] = temporary;
            }
        }
    }
    
    cout << "This is the sorted list: " << endl;
    
    for (int i = 0; i < 5; i ++)
    {
        cout << array[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}
