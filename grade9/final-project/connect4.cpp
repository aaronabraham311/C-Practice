#include <iostream>
#include "connect4.h"

using namespace std;

// Checks if there is draw. Counts all spaces to find any spaces, and if there is, the game is not a draw
bool draw(char array[6][7])
{
    bool tie = false;
    int counter = 0;
    for(int rows = 0; rows < 6; rows++)
    {
        for(int columns = 0; columns < 7; columns++)
        {
            if(array[rows][columns] != ' ')
            {
                counter++;
            }
            else
            {
                break;
            }
        }
    }
    //If no spaces, game is draw
    if(counter == 42)
    {
        tie = true;
    }
    
    return tie;
}

// Initializes function with spaces
void spaces(char array[6][7])
{
    // Updates each value with spaces
    for(int row = 0; row < 6; row++)
    {
        for(int column = 0; column < 7; column++)
        {
            array[row][column] = ' ';
        }
    }
}

// Prints array
void printArray(char Array[6][7])
{
    int counter = 0;
    cout << endl;
    cout << " 0 |  1 |  2 |  3 |  4 |  5 |  6 |" << endl;
    cout << "----------------------------------";
    for(int rows = 0; rows < 6; rows++)
    {
        cout << endl;
        cout << counter;
        counter++;
        for(int colums = 0; colums < 7; colums ++)
        {
            // Creates the board
            cout << Array[rows][colums];
            cout << " |";
            cout << "  ";
            
        }
        
        cout << endl;
        cout << "----------------------------------";
    }
    cout << endl;
    return;
}

// Drops the checker in and returns the current row
int updateboard(char Array[6][7], int column)
{
    int row = 5;
    
    // Will keep decreasing row while the previous space is filled
    if(column >= 0 && column <= 6)
    {
        while(Array[row][column] != ' ' && row >= 0)
        {
            row--;
        }
    }
    
    return row;
}

// Checks if user has 4 in a row in 1 column
bool checkColumn (char array[6][7], int userRow, int userColumn)
{
    // Finds charachter that needs to be the same and establishes counter
    char check = array[userRow][userColumn];
    int counter = 1;
    
    if (check == ' ')
    {
        return false;
    }
    
    else
    {
        // Increases row number by 1 (down column) every time and finds if there is 4 in a row by updating the counter
        for (int change = 1; change < 4; change ++)
        {
            int newRow = userRow + change;
            
            // Makes sure that newRow is valid
            if ( newRow < 0)
            {
                break;
            }
            else
            {
                if (array[newRow][userColumn] != check) // If the next row value is not the same, loop breaks
                {
                    break;
                }
                else // If the next row value is the same, counter updated by 1
                {
                    counter ++;
                }
            }
        }
        
        // If there is 4 in a row, returns true
        if (counter == 4)
        {
            return true;
        }
    }
    
    // If there is no 4 in a row, returns false
    return false;
}

// Checks is user has 4 in a row in 1 row
bool checkRow (char array[6][7], int userRow, int userColumn)
{
    // Finds charachter that needs to be the same, and establishes counter
    char check = array[userRow][userColumn];
    int counter = 0;
    
    if (check == ' ')
    {
        return false;
    }
    
    else
    {
        // Checks all columns on singular row and counts amount of counters in single row. If 4 in a row, loop breaks
        for (int column = 0; column < 7; column ++)
        {
            if (array[userRow][column] == check)
            {
                counter ++;
                
                if (counter == 4)
                {
                    break;
                }
            }
            else
            {
                counter = 0;
            }
        }
        
        // If 4 in a row, program returns true. Otherwise, returns false.
        if (counter == 4)
        {
            return true;
        }
    }
    
    // Returns false if there is no 4 in a column
    return false;
}

// Checks all diagonals to see if user has 4 in a row
bool checkDiagonal (char array[6][7], int userRow, int userColumn)
{
    
    char check = array[userRow][userColumn];
    int counter = 0;
    int newRow = userRow;
    int newColumn = userColumn;
    
    if (check == ' ')
    {
        return false;
    }
    
    else
    {
        // Getting first value of top left-bottom right diagonals
        while (true)
        {
            if ((newRow <= 0) || (newRow > 5) || (newColumn <= 0) || (newColumn > 6))
            {
                break;
            }
            newRow --;
            newColumn --;
        }
        
        // Making infinite loop to find top left-bottom right diagonals
        while (true)
        {
            // If the new row or new column is out of the board or invalid, the loop breaks
            if (((newRow < 0) || (newRow > 5)) || (newColumn < 0) || (newColumn > 6))
            {
                break;
            }
            // If the designated value is valid, it will check if the counter is equal to those values. If it is, it will add to the counter till it is 4, or it will reset the counter everytime it is different
            else
            {
                if (array[newRow][newColumn] != check)
                {
                    counter = 0;
                }
                else
                {
                    counter ++;
                }
            }
            
            // If the counter is 4, it will break. Otherwise, it will update the newRow and newColumn to go to next value of diagonal
            if (counter == 4)
            {
                break;
            }
            else
            {
                newRow ++;
                newColumn ++;
            }
        }
        
        // If the counter is 4, it will return true to the program
        if (counter == 4)
        {
            return true;
        }
        
        // Reestablishing row and column, and getting first value of top right-bottom left diagonal
        newRow = userRow;
        newColumn = userColumn;
        
        while (true)
        {
            if ((newRow <= 0) || (newRow > 5) || (newColumn < 0) || (newColumn >= 6))
            {
                break;
            }
            newRow --;
            newColumn ++;
        }
        
        // Making infinite loop to find top right-bottom left diagonals
        while (true)
        {
            // If the new row or new column is out of the board or invalid, the loop breaks
            if (((newRow < 0) || (newRow > 5)) || (newColumn < 0) || (newColumn > 6))
            {
                break;
            }
            // If the designated value is valid, it will check if the counter is equal to those values. If it is, it will add to the counter till it is 4, or it will reset the counter everytime it is different
            else
            {
                if (array[newRow][newColumn] != check)
                {
                    counter = 0;
                }
                else
                {
                    counter ++;
                }
            }
            // If the counter is 4, it will break. Otherwise, it will update the newRow and newColumn to go to next value of diagonal
            if (counter == 4)
                break;
            else
            {
                newRow ++;
                newColumn --;
            }
        }
        
        // If the counter is 4, it will return true to the program
        if (counter == 4)
            return true;
        
    }
    
    // If it hasn't returned true to the program, it will return false, as it
    return false;
    
}

// Pops out bottom counter
void popoutfunc(int column, char Array[6][7])
{
    // Moves all of the counters down 1
    Array[5][column] = Array[4][column];
    Array[4][column] = Array[3][column];
    Array[3][column] = Array[2][column];
    Array[2][column] = Array[1][column];
    Array[1][column] = Array[0][column];
    
}
