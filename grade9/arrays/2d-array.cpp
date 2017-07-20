#include <iostream>
using namespace std;

int main ()
{
    // Initializing array, user's row and column, and user's value
    float grid[3][2] = { {0,0}, {0,0}, {0,0} };
    int userRow, userColumn;
    float newValue;
    
    // Outputting original grid
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 2; column++)
            cout << grid[row][column] << " ";
        
        cout << endl;
    }
    
    // Running loop forever
    while (true)
    {
        // Getting row and column
        cout << "Please enter the row and the column you wish to change: ";
        cin >> userRow >> userColumn;
        
        // If row and column is invalid, program will break out of infinite while loop
        if ((userRow > 3 || userRow < 0) || (userColumn > 2 || userColumn < 0 ) )
            break;
        
        // Getting new value
        cout << "Please enter the new value: ";
        cin >> newValue;
        
        // Converting to program usable numbers
        userRow --;
        userColumn --;
        
        // Making specific grid place equal to user's desired value
        grid[userRow][userColumn] = newValue;
        
        // Outputting grid
        for (int row = 0; row < 3; row++)
        {
            for (int column = 0; column < 2; column++)
                cout << grid[row][column] << " ";
            
            cout << endl;
        }
    }
    
    cout << "Program has ended due to invalid row or column. " << endl;
    return 0;
}
