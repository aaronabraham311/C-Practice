#include <iostream>
using namespace std;

int main()
{
    int userNumber; // Declaring variables
    int counter = 15;
    
    do // Making sure input is a positive number
    {
        cout << "Please enter a positive number: ";
        cin >> userNumber;
    } while ( userNumber <= 0 );
    
    while ( counter >= 0) // Running the loop to output the next 15 numbers
    {
        cout << userNumber << endl;
        userNumber++;
        counter--;
    }
    
    return 0;
}
