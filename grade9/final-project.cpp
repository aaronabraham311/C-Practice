#include <iostream>
using namespace std;

// Prototypes of all functions
bool draw(char array[6][7]);
void spaces(char array[6][7]);
void printArray(char Array[6][7]);
int updateboard(char Array[6][7], int column);
bool checkColumn (char array[6][7], int userRow, int userColumn);
bool checkRow (char array[6][7], int userRow, int userColumn);
bool checkDiagonal (char array[6][7], int userRow, int userColumn);
void popoutfunc(int column, char Array[6][7]);

int main()
{
    // Declaring variables
    char ans;
    char popoutDecision;
    char array[6][7];
    int rowvalue, columnvalue, gameswon = 0, gameswon1 = 0, draws = 0;
    int playernumber = -1;
    bool invalid;
    
    // Outputting rules
    cout << endl << "CONNECT FOUR:" << endl;
    cout << "\nWelcome to a game of Connect Four!" << endl << "Connect Four is a two players game which takes place on a 6x7 rectangular board.\nEach player can drop a counter at the top of the board in one of the seven columns; the counter falls down and fills the lower unoccupied square." << endl;
    cout << "This mode of Connect Four also allows the user to 'popout' the bottom counter of any column, in exchange for a turn." << endl;
    cout << "The object of the game is to connect four counters vertically, horizontally or diagonally." << endl;
    
    do
    {
        // Outputs win counters for each player, and draw counter. Also initializes and prints board
        cout << endl << "Number of Wins: " << endl;
        cout << "Player 1: " << gameswon << endl << "Player 2: " << gameswon1 << endl;
        cout << "Number of Draws: " << draws << endl;
        
        spaces(array);
        printArray(array);
        
        // Starts turn by switching player
        do
        {
            playernumber *= -1;
            
            // Asks if user wants to pop out, and sanitizes
            if (playernumber == 1)
            {
                do
                {
                    cout << "Would you like to popout a counter, Player 1? (y/n)";
                    cin >> popoutDecision;
                }while (popoutDecision != 'y' && popoutDecision != 'n');
            }
            else
            {
                do
                {
                    cout << "Would you like to popout a counter, Player 2? (y/n)";
                    cin >> popoutDecision;
                }while (popoutDecision != 'y' && popoutDecision != 'n');
            }
            
            // If the user does want to pop out, program gets column number, sets row number for 5 (for win check) and pops out counter
            if (popoutDecision == 'y')
            {
                rowvalue = 5;
                
                do
                {
                    cout << "Please enter a valid column number: ";
                    cin >> columnvalue;
                } while (columnvalue < 0 || columnvalue > 6);
                
                popoutfunc(columnvalue, array);
            }
            
            // If user does not want to pop out, prorgam will execute normal turn, getting column values and sanitizing
            else
            {
                do
                {
                    invalid = false;
                    
                    // Gets user's column values
                    if(playernumber == 1)
                    {
                        cout << "Enter the position of your counter, Player 1(column): ";
                        cin >> columnvalue;
                    }
                    else if(playernumber == -1)
                    {
                        cout << "Enter the position of your counter, Player 2(column): ";
                        cin >> columnvalue;
                    }
                    
                    // Gets row value from function
                    rowvalue = updateboard(array, columnvalue);
                    
                    // If column is out of the board, or if the inputted column is full, it will tell user
                    if((columnvalue > 6) || (columnvalue < 0))
                    {
                        cout << "You entered an invalid value, user. Try Again." << endl;
                        invalid = true;
                    }
                    else if (array[rowvalue][columnvalue] != ' ')
                    {
                        cout << "This column is full, user. Try again." << endl;
                        invalid = true;
                    }
                    // Otherwise, the program will update the board with the respective counters
                    else
                    {
                        if (playernumber == 1)
                        {
                            array[rowvalue][columnvalue] = 'X';
                        }
                        else
                        {
                            array[rowvalue][columnvalue] = 'O';
                        }
                    }
                    
                } while(invalid == true);
                // Will keep looping until column values are valid, or if the user chooses a column that is not full
            }
            
            // Prints array
            printArray(array);
            
        }while((checkColumn(array, rowvalue, columnvalue) == false) && (checkRow(array, rowvalue, columnvalue) == false) && (checkDiagonal(array, rowvalue, columnvalue) == false) && (draw(array) == false));
        // Will keep looping code if there is no win or draw with each turn
        
        // Will check if there is a draw. If there is, it will update draw counter. Otherwise, it will tell which player has won, and update counter
        if((draw(array) == true) && (checkColumn(array, rowvalue, columnvalue) == false) && (checkRow(array, rowvalue, columnvalue) == false) && (checkDiagonal(array, rowvalue, columnvalue) == false))
        {
            cout << "The game ends in a draw!" << endl;
            draws++;
        }
        else
        {
            if(playernumber == 1)
            {
                cout << "Player 1 is the winner!" << endl;
                gameswon++;
            }
            else if(playernumber == -1)
            {
                cout << "Player 2 is the winner!" << endl;
                gameswon1++;
            }
        }
        
        // Asks user if he/she would like to play again. Sanitizes data
        do
        {
            cout << "Would you like to play again (y/n)?";
            cin >> ans;
        } while (ans != 'y' && ans != 'n');
        
    }while(ans == 'y');
    
    // Gives end message and ends progam.
    cout << "Thanks for playing!" << endl;
    
    return 0;
}

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
