#include <iostream>
using namespace std;

int main ()
{
    int userNum;
    char userChar;
    
    do
    {
        cout << "Please enter either 'u' or 'd': "; // Getting either 'u' or 'd'
        cin >> userChar;
    } while ( (userChar != 'u') && (userChar != 'd') ); // If user doesn't enter correct number, it will loop
    
    cout << "Please enter a number: "; // Getting user's number
    cin >> userNum;
    
    for (int counter = 10; counter > 0; counter--) // Setting up for loop with a counter of 10
    {
        if (userChar == 'u') // When userChar is 'u', adding 1 every time
        {
            userNum ++;
            cout << userNum << endl;
        }
        
        else if (userChar == 'd') // When userChar is 'd', subtracting 1 every time
        {
            userNum --;
            cout << userNum << endl;
        }
    }
    
    return 0;
}
