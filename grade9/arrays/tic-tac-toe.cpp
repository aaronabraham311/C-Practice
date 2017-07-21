#include <iostream>
#include <cstdlib>
using namespace std;

// Prototypes for functions
void updateInitialArray (string array[][3]);
void printGame (string array[][3]);
void printArray (string array[][3]);
void updateArray (string array[][3], int plyerNumber, int column, int row);
bool playerTurn (string array[][3], int playerNumber, string p1name, string p2name);
bool gameStatus (string array[][3], int playerNumber, int userRow, int userColumn);

int main ()
{
    // Seeding random value with time
    srand(time(NULL));
    
    // Declaring variables
    string player1Name, player2Name;
    string gameArray[3][3];
    bool gameStatus;
    int gameCounter = 1;
    int player1Counter = 0, player2Counter = 0;
    char userReplayChoice;
    
    // Getting names for game
    cout << "Player 1, please enter your name: ";
    cin >> player1Name;
    
    cout << "Player 2, please enter your name: ";
    cin >> player2Name;
    
    // Deciding which player should go first (number from expression tells program who goes first) using random number
    int playerNumber = rand() % 2;
    
    do
    {
        // Initializing array with spaces
        updateInitialArray (gameArray);
        
        // Outputing number of times players have won
        cout << player1Name << ", you have won " << player1Counter << " times. ";
        cout << player2Name << ", you have won " << player2Counter << " times. " << "\n" << endl;
        
        // Until game draws (if turns reach 9), game gets input information
        for (gameCounter = 1; gameCounter <= 9; gameCounter ++)
        {
            // Updates array, and finds if game has been won by player
            gameStatus = playerTurn (gameArray, playerNumber, player1Name, player2Name);
            
            if (gameStatus == true)
                break;
            
            // Switches players
            if (playerNumber == 0)
                playerNumber = 1;
            else
                playerNumber = 0;
        }
        
        // If game has not drawn
        if (gameStatus == true)
        {
            // Outputs player 1 won
            if (playerNumber == 0)
            {
                printGame (gameArray);
                cout << player1Name << ", you have won!" << endl;
                player1Counter ++;
            }
            // Outputs player 2 won
            else if (playerNumber == 1)
            {
                printGame (gameArray);
                cout << player2Name << ", you have won!" << endl;
                player2Counter ++;
            }
        }
        // If game is drawn, game is outputted and tells that it is drawn
        else
        {
            printGame (gameArray);
            cout << "The game ended in a draw." << endl;
        }
        
        // Asks if user wants to play again (makes sure decision is either y or n)
        do
        {
            cout << "Do you want to play again? (y/n) ";
            cin >> userReplayChoice;
        } while ( (userReplayChoice != 'n') && (userReplayChoice != 'y'));

    } while (userReplayChoice == 'y');
    
    cout << "Have a good day! " << endl;
    
    return 0;
}

// Initializes array with spaces
void updateInitialArray (string array[][3])
{
    for (int row = 0; row < 3; row ++)
    {
        for (int column = 0; column < 3; column ++)
        {
            array[row][column] = " ";
        }
    }
    return;
}

// Updates array if X if player 1 is playing, or 0 if O if player 2 is playing
void updateArray (string array[][3], int playerNumber, int column, int row)
{
    if (playerNumber == 1)
    {
        array[row][column] = "X";
    }
    else
    {
        array[row][column] = "O";
    }
}

// Prints the game nicely
void printGame (string array[][3])
{
    for (int row = 0; row < 3; row ++)
    {
        cout << "_____________" << endl;
        cout << "|";
        
        for (int column = 0; column < 3; column ++)
        {
            cout << " " << array[row][column] << " |";
        }
        cout << endl;
    }
    
    cout << "_____________" << endl;
    return;
}

bool playerTurn (string array[][3], int playerNumber, string p1name, string p2name)
{
    int userRow, userColumn;
    bool status;
    
    // Tells which player is playing
    if (playerNumber == 0)
        cout << p1name << ", it is your turn." << endl;
    else
        cout << p2name << ", it is your turn." << endl;
    
    // Prints game
    printGame (array);
    
    // Makes sure that the user enters valid row and column to input it
    do
    {
        cout << "Please enter a valid desired row and column respectively, which is not already claimed, seperated by spaces: ";
        cin >> userRow >> userColumn;
    } while ( (userRow > 3 || userRow <= 0) || (userColumn > 3 || userColumn <= 0));
    
    // Makes row and column usable by program
    userRow --;
    userColumn --;
    
    // If the user enters an already used space, program asks for new column and row
    while (array[userRow][userColumn] != " ")
    {
        do
        {
            cout << "Please enter a valid desired row and column respectively, which is not already claimed, seperated by spaces: ";
            cin >> userRow >> userColumn;
        } while ( (userRow > 3 || userRow <= 0) || (userColumn > 3 || userColumn <= 0));
        
        // Makes row and column usable by program
        userRow --;
        userColumn --;
    }
    
    // Updates array and checks is game has been won
    updateArray (array, playerNumber, userColumn, userRow);
    status = gameStatus (array, playerNumber, userRow, userColumn);
    
    return status;
}

bool gameStatus (string array[][3], int playerNumber, int userRow, int userColumn)
{
    string findChar;
    bool check = false;
    
    // Tells program which charachter should be compared to
    if (playerNumber == 0)
        findChar = "O";
    else
        findChar = "X";
    
    // Checks is row and column are all same charachter
    if ((array[userRow][0] == findChar) && (array[userRow][1] == findChar) && (array[userRow][2] == findChar))
    {
        check = true;
    }
    else if ((array[0][userColumn] == findChar) && (array[1][userColumn] == findChar) && (array[2][userColumn] == findChar))
    {
        check = true;
    }
    
    // If user enters top left corner as position
    if ((userRow == 0) && (userColumn == 0))
    {
        // If diagonal is all same, status becomes true
        if ((array[userRow + 1][userColumn + 1] == findChar) && (array[userRow + 2][userColumn + 2] == findChar))
        {
            check = true;
        }
    }
    // If user enters bottom right corner, it checks diagonal if all charachters are the same
    else if ((userRow == 2) && (userColumn == 2))
    {
        if ((array[userRow - 1][userColumn - 1] == findChar) && (array[userRow - 2][userColumn - 2] == findChar))
        {
            check = true;
        }
    }
    // If user enters bottom left corner, it checks diagonal if all charachters are the same
    else if ((userRow == 2) && (userColumn == 0))
    {
        if ((array[userRow - 1][userColumn + 1] == findChar) && (array[userRow - 2][userColumn + 2] == findChar))
        {
            check = true;
        }
    }
    // If user enters top right corner, it checks diagonal if all charachters are the same
    else if ((userRow == 0) && (userColumn == 2))
    {
        if ((array[userRow + 1][userColumn - 1] == findChar) && (array[userRow + 2][userColumn - 2] == findChar))
        {
            check = true;
        }
    }
    // If user enters middle position, checks both diagonals if all charachters are same
    else if ((userRow == 1) && (userColumn == 1))
    {
        if ((array[userRow - 1][userColumn - 1] == findChar) && (array[userRow + 1][userColumn + 1] == findChar))
        {
            check = true;
        }
        else if ((array[userRow + 1][userColumn - 1] == findChar) && (array[userRow - 1][userColumn + 1] == findChar))
        {
            check = true;
        }
    }
    // Returns status
    return check;
    
}
