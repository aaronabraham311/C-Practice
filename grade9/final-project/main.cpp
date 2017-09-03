#include <iostream>
#include "connect4.h"
using namespace std;

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
