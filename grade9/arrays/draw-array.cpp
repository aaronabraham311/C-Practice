#include <iostream>
using namespace std;

// Establishing fucntions
void updateInitialArray (char array[][5], int rowNumber);
void updateArray (char array[][5], int row, int column);
void printArray (char array[][5]);

int main ()
{
    // Making array, upating initial array, and making variable for user's decision
    char userArray [5][5];
    char userDecision;
    updateInitialArray(userArray, 5);
    
    // Making do while loop, that loops if user wants to redo it
    do
    {
        // Making variables for row and column of user, and printing array
        int rowNumber, columnNumber;
        
        printArray (userArray);
        
        // Getting row and column, and breaking program if invalid
        cout << "Please enter the row number and column number: ";
        cin >> rowNumber >> columnNumber;
        
        if ((rowNumber <= 0 || rowNumber > 5) || (columnNumber <= 0 || columnNumber > 5))
            break;
        
        // Making row and column usable by computer
        rowNumber --;
        columnNumber --;
        
        // Updating and priting array
        updateArray (userArray, rowNumber, columnNumber);
        printArray (userArray);
        
        // Asking if user wants to continue, and repeateding until valid answer is given
        do
        {
            cout << "Do you want to continue updating? (y/n) ";
            cin >> userDecision;
        } while (userDecision != 'n' && userDecision != 'y');
    } while (userDecision == 'y');
    
    cout << "Program has finished due to either your decision or invalid input." << endl;
    return 0;
}

// Prints array
void printArray (char array[][5])
{
    for (int row = 0; row < 5; row ++)
    {
        for (int column = 0; column < 5; column ++)
        {
            cout << array[row][column];
        }
        cout << endl;
    }
    
    return;
}

// Updates initial array with '*'
void updateInitialArray (char array[][5], int rowNumber)
{
    for (int row = 0; row < rowNumber; row ++)
    {
        for (int column = 0; column < 5; column ++)
        {
            array[row][column] = '*';
        }
    }
}

// Updates array with 'o' if '*', or '*' if 'o'
void updateArray (char array[][5], int row, int column)
{
    if (array[row][column] == 'o' )
    {
        array[row][column] = '*';
    }
    
    else
    {
        array[row][column] = 'o';
    }
    
    
    return;
}
