#include <iostream>

using namespace std;

// Recursive function declaration
int factorial (int number);
int gcf (int num1, int num2);
int sum (int number);
int intPower (int base, int exponent);

int main()
{
    // Declaring all variables
    int userNumber, userNumber2;
    int userDecision;
    
    // Asks user for which program to run and validating results
    do
    {
        cout << "Which program would you like to run (1, 2, 3, 4)? ";
        cin >> userDecision;
    } while (userDecision != 1 && userDecision != 2 && userDecision != 3 && userDecision != 4); // Will not run until user enters 1, 2, 3 or 4
    
    if (userDecision == 1) // Factorial program
    {
        do
        {
            cout << "Please enter a positive natural number: ";
            cin >> userNumber;
        } while (userNumber <= 0); // Asking for positive number and validating results
        
        cout << "The factorial of your number is: " << factorial (userNumber) << endl; // Outputting factorial

    }
    else if (userDecision == 2) // GCF program
    {
        do
        {
            cout << "Please enter 2 positive natural numbers: ";
            cin >> userNumber >> userNumber2;
        } while (userNumber <= 0 || userNumber2 <= 0); // Asking for 2 numbers and making sure that numbers are positive
        
        cout << "The GCF of the two numbers: " << gcf (userNumber, userNumber2) << endl; // Outputting GCF program
    }
    else if (userDecision == 3) // Sum program
    {
        do
        {
            cout << "Please enter a positive natural number: ";
            cin >> userNumber;
        } while (userNumber < 0); // Getting a number and making sure it is positive
        
        cout << "The sum of all natural numbers of your number is: " << sum (userNumber) << endl; // Outputting sum
    }
    else if (userDecision == 4) // Integer power program
    {
        do
        {
            cout << "Please enter the base number: ";
            cin >> userNumber;
            
            cout << "Please enter the exponent: ";
            cin >> userNumber2;
        } while (userNumber2 < 0); // Getting base and exponent and making sure exponent is positive
        
        cout << "The integer power is: " << intPower(userNumber, userNumber2) << endl; // Outputting integer power
    }
    
    cout << "Please re-compile program if you would like to run more programs. " << endl;
    
    return 0;
}

// Definition of factorial function
int factorial (int number)
{
    if (number == 1) // Returns number when number is 1
    {
        return 1;
    }
    else
    {
        return number * factorial (number - 1); // Returns n * (n-1), creating a recursive stack
    }
}

// Definition of GCF function
int gcf (int num1, int num2)
{
    if (num2 == 0) // Outputting first number once it is 0
    {
        return num1;
    }
    else
    {
        return gcf(num2, num1 % num2); // Calling function, but putting second value as first value, and finding remainder of division
    }
}

// Definition of sum function
int sum (int number)
{
    if (number == 0) // Will return 0 once number is 0
    {
        return 0;
    }
    else
    {
        return number + sum(number - 1); // Adding n with (n-1)
    }
}

int intPower (int base, int exponent)
{
    if (base == 0) // Returns 0 is base is 0
    {
        return 1;
    }
    else if (exponent == 1) // Returns base number if exponent is 1
    {
        return base;
    }
    else
    {
        return base * intPower (base, exponent - 1); // Returns base * (base ^ (n-1))
    }
}
