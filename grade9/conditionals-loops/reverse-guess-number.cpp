#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main ()
{
    char userReplay;
    
    do
    {
        cout << "Welcome to Guess the Number. You can input a number of your choosing that is between 0 and 100 (inclusive) and you can input 'Higher' or 'Lower' if Mycroft (the computer) guesses the wrong number. Can you match your wits against Mycroft?" << endl;
        
        
        int counter;
        srand (time(NULL));
        int randomNumber = rand() % 101;
        int randomNumberHighest = 100;
        int randomNumberLowest = 0;
        string userAnswer;
        
        for (counter = 1; counter < 1000000; counter ++)
        {
            do
            {
                cout << "\nMy guess is: " << randomNumber << ". Is that correct? Please enter either 'Higher' if my guess is lower, or 'Lower' if my guess is higher. If I am correct, please enter 'Correct'. " << endl;
                cin >> userAnswer;
            } while (!((userAnswer == "Higher") || (userAnswer == "Lower") || (userAnswer == "Correct")));
            
            if ( userAnswer == "Higher")
            {
                randomNumberLowest  = randomNumber;
            }
            
            else if ( userAnswer == "Lower")
            {
                randomNumberHighest = randomNumber;
            }
            
            else
                break;
            
            randomNumber = (rand() % (randomNumberHighest - randomNumberLowest) + randomNumberLowest);
        }
        
        do
        {
            cout << "I was correct! I guessed "<< randomNumber << " in " << counter << " guesses. Do you want to play again? Please enter either 'y' for yes or 'n' for no: " << endl;
            cin >> userReplay;
        } while ( !( (userReplay == 'y') || (userReplay == 'n')));
        
    } while ( userReplay == 'y');
    
    cout << "Thank you for playing! Have a great day. " << endl;
    
    return 0;
}
