#include <iostream>

using namespace std;

// Declaring class
class Class
{
private:
    double number1; // Declaring two variables to host number
    double number2;
public:
    void getValue(); // Function to get the values for number1 and number2
    void display(); // Function to display number 1 and number 2
    Class operator + (Class object); // Adds corresponding numbers from two objects together
    Class operator - (Class object); // Subtracts corresponding numbers from two objects from each each other
    Class operator * (Class object); // Multiplies corresponding numbers from two objects together
    Class operator / (Class object); // Divides corresponding numbers from two objects from each other
};

int main()
{
    Class object1, object2, object3; // Declaring 3 objects. Third object is the object that will
    char userOperation, userDecision;
    
    do
    {
        cout << "Welcome to the Object Calculator. " << endl;
        cout << "************************" << endl;
        
        // Inputting the values for Object 1
        cout << "Object 1 Values: " << endl;
        object1.getValue();
        cout << "************************" << endl;
        
        // Inputting the values for Object 2
        cout << "Object 2 Values: " << endl;
        object2.getValue();
        cout << "************************" << endl;
        
        // Getting the operation that is going to be applied to the two objects
        do
        {
            cout << "Please enter the operation you would like to do: ";
            cin >> userOperation;
        } while (userOperation != '+' && userOperation != '-' && userOperation != '*' && userOperation != '/'); // Validating operation
        
        // Making switch statement to do specific operation for object
        switch (userOperation)
        {
            case '+':
                object3 = object1 + object2; // Adding two objects together into new object
                break;
            case '-':
                object3 = object1 - object2; // Subtracting two objects from each other
                break;
            case '*':
                object3 = object1 * object2; // Multiplying two objects together
                break;
            case '/':
                object3 = object1 / object2; // Dividing two objects
        }
        
        object3.display(); // Displaying new object
        
        // Askking user if they would like to run the program again
        do
        {
            cout << "Would you like to do another operation or add more values? (y/n)";
            cin >> userDecision;
            
        } while (userDecision != 'y' && userDecision != 'n'); // Validating input to make sure it is not 'y' or 'n'
  
    } while (userDecision == 'y');
    
    cout << "Have a good day! " << endl; // Giving closing message
    
    return 0;
}

// Member function to input two numbers
void Class:: getValue()
{
    cout << "Please enter the values of the two numbers: ";
    cin >> number1 >> number2;
    
    return;
}

// Member function to output two numbers
void Class:: display()
{
    cout << "Number 1: " << number1 << endl;
    cout << "Number 2: " << number2 << endl;
    
    return;
}

// Overloading '+' operator to add two objects
Class Class:: operator + (Class object)
{
    Class testObject; // Creating temporary object
    
    // Updating object's numbers by adding given object and object that is being added to it
    testObject.number1 = number1 + object.number1;
    testObject.number2 = number2 + object.number2;
    
    return testObject; // Returning temporary object
}

// Overloading '-' operator to subtract two objects
Class Class:: operator - (Class object)
{
    Class testObject; // Creating temporary object
    
    // Updating object's numbers by subtracting given object and object that is being added to it
    testObject.number1 = number1 - object.number1;
    testObject.number2 = number2 - object.number2;
    
    return testObject; // Returning temporary object
}

// Overloading '*' operator to add two objects
Class Class:: operator * (Class object)
{
    Class testObject; // Creating temporary object
    
    // Updating object's numbers by multiplying given object and object that is being added to it
    testObject.number1 = number1 * object.number1;
    testObject.number2 = number2 * object.number2;
    
    return testObject; // Returning temporary object
}

// Overloading '/' operator to add two objects
Class Class:: operator / (Class object)
{
    Class testObject; // Creating temporary object
    
    // Updating object's numbers by multiplying given object and object that is being added to it
    testObject.number1 = number1 / object.number1;
    testObject.number2 = number2 / object.number2;
    
    return testObject; // Returning temporary object
}
