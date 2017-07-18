/* Aaron Abraham
 Dec. 3, 2015
 Programming 9 - Random Number Generator */


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main ()
{
    srand (time(NULL));
    
    char userNumberType;
    
    do // Getting user input if user wants random decimals or random integers and sanitizing
    {
        cout << "Please enter 'd' for a random decimal or 'i' for integer: ";
        cin >> userNumberType;
    } while ( (userNumberType != 'i') && (userNumberType != 'd'));
    
    if (userNumberType == 'i') // If user wants integers, outputting 10 random integers, and allowing variables as integers
    {
        int lowerRestriction; // Declaring integer variables
        int upperRestriction;
        int userOutput;
        
        do // Getting restrictictions and making sure lower restriction is not equal to or greater than higher restriction
        {
            cout << "Please enter your lowest restriction: ";
            cin >> lowerRestriction;
            
            cout << "Please enter your upper restriction: ";
            cin >> upperRestriction;
        } while (lowerRestriction >= upperRestriction);
        
        cout << "Your 10 random numbers are: " << endl; // Starting output
        
        for (int counter = 0; counter < 10; counter ++)
        {
                userOutput = (rand() % (upperRestriction - lowerRestriction)) + lowerRestriction;
                cout << userOutput << endl;
        }
        
    }
    
    else if (userNumberType == 'd') // If user wants decimals, outputting 10 random decimals and allowing variables as decimals
    {
        float lowerRestriction; // Declaring decimal outputs
        float upperRestriction;
        float userOutput;
        
        do // Getting restrictictions and making sure lower restriction is not equal to or greater than higher restriction
        {
            cout << "Please enter your lowest restriction: ";
            cin >> lowerRestriction;
            
            cout << "Please enter your upper restriction: ";
            cin >> upperRestriction;
        } while (lowerRestriction >= upperRestriction);
        
        cout << "Your 10 random numbers are: " << endl; // Starting output
        
        for (int counter = 0; counter < 10; counter ++)
        {
            userOutput = (upperRestriction - lowerRestriction)*(float (rand())/(RAND_MAX)) + lowerRestriction;
            cout << userOutput << endl;
        }
    }
    
    return 0;
}
