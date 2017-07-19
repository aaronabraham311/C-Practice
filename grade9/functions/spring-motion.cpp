#include <iostream>
#include <fstream>
using namespace std;

// Setting prototypes for functions
float updateAcc (float, float);
float updateVelo (float, float, float);
float updatePos (float, float, float);

int main ()
{
    // Setting up file
    ofstream objectSpringFile;
    objectSpringFile.open("objectSpringFile.txt");
    objectSpringFile << "Time" << "\t" << "Position" << endl;
    
    // Initializing variables
    float initialPosition, springConstant, timeIncrement, finalTime;
    
    // Getting initial position
    cout << "Please enter the initial position of the weight: " ;
    cin >> initialPosition;
    
    // Getting spring constant, and making sure it is above 0
    do
    {
        cout << "Please enter the spring constant: ";
        cin >> springConstant;
    } while (springConstant <= 0);
    
    // Getting time increment, and making sure it is below 1
    do
    {
        cout << "Please enter the desired time increment: ";
        cin >> timeIncrement;
    } while (timeIncrement > 1);
    
    // Getting final time, and making sure it is above zero
    do
    {
        cout << "Please enter the final time: ";
        cin >> finalTime;
    } while (finalTime <= 0);
    
    // Setting initial values of variables
    float velocity = 0;
    float currentTime = 0;
    float acceleration = 0;
    float position = initialPosition;
    
    // Putting initial values of time and position of weight
    objectSpringFile << currentTime << "\t" << position << endl;
    
    // Updating position when the current time is less than the designated final time
    while (currentTime <= finalTime)
    {
        acceleration = updateAcc (springConstant, position); // Updating acceleration based on position
        
        velocity = updateVelo (velocity, acceleration, timeIncrement); // Updating velocity based on previous velocity, acceleration, and designated time increment
        
        position = updatePos (velocity, timeIncrement, position); // Updating position by using previous position, the designated time increment and the velocity
        
        currentTime += timeIncrement; // Updating time based on designated time increment
        
        objectSpringFile << currentTime << "\t" << position << endl; // Outputting position and current time to file
    }
    
    // Closing int main() and file
    objectSpringFile.close();
    return 0;
}

float updateAcc (float springConstant, float position)
{
    float acceleration = -1 * springConstant * position; // Using formula a = -ky to update acceleration
    return acceleration;
}

float updateVelo (float velocity, float acceleration, float timeIncrement)
{
    velocity += acceleration * timeIncrement; // Updating velocity by adding the change in velocity due to acceleration to previous value
    return velocity;
}

float updatePos (float velocity, float timeIncrement, float position)
{
    position += velocity * timeIncrement; // Updating position by using D = VT formula
    return position;
}

