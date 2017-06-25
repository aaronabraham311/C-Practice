#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main ()
{
    char userReplay; // Initialzing decision to play agin here to allow 'global' scope
    
    do // Initializing do - while loop to allow user to play again
    {
        srand (time(NULL));
        int randomNumber = rand() % 100; // Making random number that is between 0 and 100
        
        int counter; // Initialzing counter here to allow 'global' scope

        cout << "Welcome to Guess the Number. The computer will make a random number, and you will have to guess! Good luck! " << endl; // Outputting welcome message
        
        for (counter = 1; counter <= 100000; counter ++) // Initiaizing loop to allow repeat guesses
        {
            int userGuess;
            
            do // Sanitizing user's guess to make sure it isn't above 100 or below 0
            {
                cout << "Please enter your guess. Please make sure it is between 0 and 100 (inclusive): "; // Getting user's guess
                cin >> userGuess;
            } while ( (userGuess > 100) || (userGuess < 0));
            
            if ( userGuess < randomNumber ) // If user's guess is less than the random number
            {
                cout << "Higher. Try again.";
            }
            else if ( userGuess > randomNumber ) // If user's guess is lower than the random number
            {
                cout << "Lower. Try again. ";
            }
            else // If user gets the right number, will break program
                break;
        }
        
        cout << "You won! The random number is " << randomNumber << " and you had " << counter << " guesses. Well done!" << endl; // Outputting the result if person won
        
        do // Getting input if user wants to play again and sanitizing data to make sure it is either 'y' or 'n'
        {
            cout << "Do you want to play again? Please enter 'y' for yes or 'n' for 'no': ";
            cin >> userReplay;
        } while ( !((userReplay == 'n') || (userReplay == 'y')));
        
    } while ( userReplay == 'y');
    
    cout << "Thank you for playing Guess the Number. Have a wonderful day!" << endl; // Outputting exit message
    
    return 0;
}
