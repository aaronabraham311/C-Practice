#include <iostream>

using namespace std;

class Class
{
private:
    int firstNumber, secondNumber;
public:
    void getValues ();
    void displayValues ();
    Class operator ++ ();
    Class operator -- ();
};

int main()
{
    Class someObject;
    
    someObject.getValues();
    ++ someObject;
    someObject.displayValues();
     -- someObject;
    someObject.displayValues();
    
    return 0;
}

Class Class:: operator++()
{
    Class testObject;
    
    testObject.firstNumber = firstNumber ++;
    testObject.secondNumber = secondNumber ++;
    
    return testObject;
}

Class Class:: operator--()
{
    Class testObject;
    
    testObject.firstNumber = firstNumber --;
    testObject.secondNumber = secondNumber --;
    
    return testObject;
}

void Class:: getValues()
{
    cout << "Please enter two numbers: ";
    cin >> firstNumber >> secondNumber;
    
    return;
}

void Class:: displayValues ()
{
    cout << "Your new first number is: " << firstNumber << endl;
    cout << "Your new second number is: " << secondNumber << endl;
    
    return;
}
