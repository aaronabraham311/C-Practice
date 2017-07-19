#include <iostream>

using namespace std;

float powerFunction (float, float);

int main ()
{
    int userNumber, userPower;
    
    cout << "Please enter a number to be squared: ";
    cin >> userNumber;
    
    cout << "Please enter the number you want you original number to be raised to: ";
    cin >> userPower;
    
    cout << "Your new number is: " << powerFunction (userNumber, userPower) << endl;
    
    return 0;
}

float powerFunction (float userNumber, float userPower)
{
    int answer = 1;
    
    for (int counter = userPower; counter > 0; counter --)
    {
        answer *= userNumber;
    }
    
    return answer;
}
