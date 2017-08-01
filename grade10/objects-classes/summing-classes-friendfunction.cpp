#include <iostream>

using namespace std;

// Initializing classes
class FirstClass;
class SecondClass;

// Declaring first class
class FirstClass
{
private:
    double number1 = 79; // Initializing number
public:
    friend double sum (FirstClass firstNumber, SecondClass secondNumber); // Making friend function
};

// Declaring second class
class SecondClass
{
private:
    double number2 = 20; // Initializing number
public:
    friend double sum (FirstClass firstNumber, SecondClass secondNumber); // Making friend function
};

int main ()
{
    // Making number objects
    FirstClass number1;
    SecondClass number2;
    
    cout << sum (number1, number2) << endl; // Giving objects to sum function and outputting value
    
    return 0;
}

double sum (FirstClass firstNumber, SecondClass secondNumber)
{
    return firstNumber.number1 + secondNumber.number2; // Returning sum of two numbers
}
