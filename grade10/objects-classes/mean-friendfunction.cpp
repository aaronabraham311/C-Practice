#include <iostream>

using namespace std;

// Declaring class
class Base
{
private:
    double number1, number2, number3; // Variables for numbers
public:
    void input(); // Declaring function for inputting variables
    friend double mean(Base number); // Declaring friend function to output mean of numbers
};

int main()
{
    Base userNumbers; // Declaring objects
    
    userNumbers.input(); // Calling function to input variables
    cout << mean(userNumbers) << endl; // Calling function to output mean
    
    return 0;
}

void Base :: input()
{
    
    cout << "Please input three numbers: ";
    cin >> number1 >> number2 >> number3; // Getting numbers
    
    return;
}

double mean (Base number)
{
    return (number.number1 + number.number2 + number.number3) / 3; // Returning mean
} 
