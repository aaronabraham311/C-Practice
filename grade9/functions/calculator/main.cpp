// Includes libraries and header file
#include <iostream>
#include "Aaron_Header.hpp"

using namespace std;

int main ()
{
    int firstUserNumber, secondUserNumber;
    char userDecision;
    
    // Gets numbers from user
    cout << "Please enter 2 whole numbers: ";
    cin >> firstUserNumber >> secondUserNumber;
    
    // Finds from user if they want to add, subtract, multiply, divide or modulo the numbers
    do
    {
        cout << "Please enter the following charachters to do the following: " << endl;
        cout << " Addition ('a') \n Subtract ('s') \n Multiply ('m') \n Divide ('d') \n Modulo ('%') " << endl;
        cin >> userDecision;
    } while (userDecision != 'a' && userDecision != 's' && userDecision != 'm' && userDecision != 'd' && userDecision != '%');
    
    // For every decision, the program returns the required sum/product/quotient/remainder from source files
    switch (userDecision)
    {
        case 'a':
            cout << "The sum of " << firstUserNumber << " and " << secondUserNumber << " is: " << add(firstUserNumber, secondUserNumber) << endl;
            break;
        case 's':
            cout << "The difference between " << firstUserNumber << " and " << secondUserNumber << " is: " << subtract (firstUserNumber, secondUserNumber) << endl;
            break;
        case 'm':
            cout << "The product of " << firstUserNumber << " and " << secondUserNumber << " is: " << multiply (firstUserNumber, secondUserNumber) << endl;
            break;
        case 'd':
            cout << "The integer quotient of dividing these two numbers is: " << divide(firstUserNumber, secondUserNumber) << endl;
            break;
        case '%':
            cout << "The remainder of these two numbers after division is: " << modulo (firstUserNumber, secondUserNumber) << endl;
            break;
        default:
            break;
    }
    
    return 0;
}
