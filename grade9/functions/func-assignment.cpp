#include <iostream>

using namespace std;

//Function prototypes
string dots ();
int factorial (int);
float area (float, float);

int main ()
{
    // Outputs dots
    cout << "The line of dots are: " << dots() << endl;
    
    // Factorial part of program
    int userNumber;
    
    cout << "Please enter a number: ";
    cin >> userNumber;
    
    cout << "The factorial of your number is: " << factorial (userNumber) << endl;
    
    // Rectangle area
    float userLength, userWidth;
    
    cout << "Please enter your width: ";
    cin >> userWidth;
    
    cout << "Please enter your length: ";
    cin >> userLength;
    
    cout << "The dimensions of your rectangle is: " << userLength << " by " << userWidth << ". \nThe area of your rectangle is: " << area (userLength, userWidth) << endl;
    
    return 0;
}

// Function outputs three dots
string dots ()
{
    string dots = "...";
    return dots;
}

// Function finds factorial of number
int factorial (int number)
{
    for (int multiplier = number - 1; multiplier > 0; multiplier--)
    {
        number = number * multiplier;
    }
    
    return number;
}

// Function finds area of rectangle
float area (float length, float width)
{
    float answer = length * width;
    return answer;
}
