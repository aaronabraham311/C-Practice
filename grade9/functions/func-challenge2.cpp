#include <iostream>
#include <string>

using namespace std;

// Prototyping function
int factor (int);

int main ()
{
    int userNumber;
    
    cout << "Please enter a number: ";
    cin >> userNumber;
    
    cout << "Your number has: " << factor (userNumber) << " factors." << endl;
    return 0;
}

// Defining function
int factor (int number)
{
    int factorCounter = 0;
    
    for (int divisor = 1; divisor <= number; divisor ++)
    {
        if ( (number % divisor) == 0)
        {
            factorCounter ++;
        }
    }
    
    return factorCounter;
}
