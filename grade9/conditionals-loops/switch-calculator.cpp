#include <iostream>
#include <string>
using namespace std;

int main ()
{
    double userNum1; // Declaring variables
    double userNum2;
    double answer;
    char userOperation;
    
    cout << "Please enter the first number: "; // Getting user's first number
    cin >> userNum1;
    
    cout << "Please enter the second number: "; // Getting user's second number
    cin >> userNum2;
    
    cout << "Which operation would you like to do? Please enter:\n '+' for addition\n '-' for subtraction\n '*' for multiplication\n '/' for division: " << endl;
    cin >> userOperation; // Getting user's operation
    
    switch (userOperation) // Declaring a switch
    {
            case '+': // If user wants to add, number will multiply
            cout << "Adding your first number to your second number: " << endl;
            answer = userNum1 + userNum2;
            break;
            
            case '-': // If user wants to subtract, second number will subtract from first number
            cout << "Subtracting your second number from your first number: " << endl;
             answer = userNum1 - userNum2;
            break;
            
            case '*': // If user wants to multiply, numbers will multiply
            cout << "Multiplying your first number by your second number: " << endl;
             answer = userNum1 * userNum2;
            break;
            
            case '/': // If user wants to divide, second number will divide first number
            cout << "Dividing your first number by the second number: " << endl;
             answer = userNum1 / userNum2;
            break;
            
            default: // If user doesn't enter compatible operation
            cout << "Please try again" << endl;
    }
    // Outputting result
    cout << " Your new number is: " << userNum1 << " " << userOperation << " " << userNum2 << " = "<< answer << endl;
    
    return 0;
}

