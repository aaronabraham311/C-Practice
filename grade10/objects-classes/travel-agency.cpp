// Declaring libraries
#include <iostream>
#include <string>

using namespace std;

// Declaring class
class Flight
{
private:
    // Declaring private varibles for flight number, destination, distance traveled and fuel used
    int flightNum;
    string destination;
    float distance;
    float fuel;
public:
    void CALFUEL (float distance); // Calculates fuel based on distance
    void FEEDINFO (); // Gets information from user
    void SHOWINFO (); // Shows information to user
};

int main()
{
    Flight userFlight; // Declaring object
    
    cout << "Hello! Welcome to the travel agency program." << endl; // Introducing program
    
    userFlight.FEEDINFO(); // Calling function to get information
    
    return 0;
}

void Flight:: CALFUEL(float distance)
{
    if (distance <= 1000)
    {
        fuel = 500; // Gives fuel value of 500 if distance travelled is less than or equal to 1000
    }
    else if (distance > 1000 && distance <= 2000)
    {
        fuel = 1100; // Gives fuel value of 1100 if distance travelled is greater than 1000 and less than or equal to 2000
    }
    else if (distance > 2000)
    {
        fuel = 2200; // Gives fuel value of 2200 if distance travelled is greater than 2000
    }
    
    return;
}

void Flight:: FEEDINFO ()
{
    char userDecision; // Declaring variable for user decision
    
    // Getting flight number and making sure it is greater than 0
    do
    {
        cout << "Please enter the flight number: ";
        cin >> flightNum;
    } while (flightNum < 0);
    
    // Getting destination
    cout << "Please enter the destination of the flight: ";
    cin.ignore();
    getline(cin, destination);
    
    // Getting distance travelled and making sure distance is greater than 0
    do
    {
        cout << "Please enter the distance that the airplane will travel: ";
        cin >> distance;
    } while (distance < 0);
    
    CALFUEL(distance); // Calling function to calculate fuel value
    
    // Asking user if they want to look at purchase info
    do
    {
        cout << "Would you like to review the purchase information? (y/n) ";
        cin >> userDecision;
    } while (userDecision != 'y' && userDecision != 'n'); // Making sure input is correct
    
    if (userDecision == 'y')
    {
        SHOWINFO(); // Calls function to show all info
    }
    else
    {
        cout << "Have a good day!" << endl; // Ends program with farewell
    }
}

void Flight:: SHOWINFO()
{
    char userDecision; // Declaring variable for decisions
    
    // Displaying information
    cout << "*****************************" << endl;
    
    cout << "Flight number: " << flightNum << endl;
    cout << "Destination: " << destination << endl;
    cout << "Distance flown: " << distance << endl;
    cout << "Fuel value: " << fuel << endl;
    
    cout << "*****************************" << endl;
    
    // Asking user if they want to change the information
    do
    {
        cout << "Would you like to change the purchase information? (y/n) ";
        cin >> userDecision;
    } while (userDecision != 'y' && userDecision != 'n'); // Making sure input is correct
    
    if (userDecision == 'y')
    {
        FEEDINFO(); // Will call function to change info
    }
    else
    {
        cout << "Have a good day!" << endl; // Ends program with farewell
    }
    
    return;
}
