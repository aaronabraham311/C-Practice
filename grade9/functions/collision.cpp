#include <iostream>
#include <fstream>

using namespace std;

// Setting up prototypes
float position (float, float);
bool inBetween (float, float, float);

int main()
{
    // Declaring variables
    float userVelocity, userTime, userLowerBound, userUpperBound, userDistance;
    float currentTime = 0;
    float changeInTime = 0.1;
    bool boundPosition;
    
    // Setting up file
    ofstream objectDistance;
    objectDistance.open("Distance of Object.txt");
    
    // Getting velocity, time and acceleration from user
    cout << "Please enter the velocity of the object: ";
    cin >> userVelocity;
    
    cout << "Please enter the initial position of the object: ";
    cin >> userDistance;
    
    cout << "Please enter the time at which you would like to see the position of the object: " ;
    cin >> userTime;
    
    cout << "Please enter the lower bound and the upper bound of the position and seperate with spaces: " ;
    cin >> userLowerBound >> userUpperBound;
    
    // Setting up axis
    objectDistance << "Time" << "\t" << "Distance" << endl;
    objectDistance << 0.0 << "\t" << userDistance << endl;
    
    // Making sure time increments is always < or = the time inputted by user
    while (currentTime <= userTime)
    {
        currentTime += changeInTime; // Increasing time by 0.1 s
        userDistance += position (userVelocity, changeInTime); //Updating position based on velocity and time
        
        boundPosition = inBetween (userDistance, userLowerBound, userUpperBound); // Checking if position is between bounds
        
        if (boundPosition == true) // If position is at or between bounds, velocity will reverse
        {
            userVelocity *= -1;
        }
        
        objectDistance << currentTime << "\t" << userDistance << endl; // Outputting time and position to file
    }
    
    objectDistance.close();
    
    return 0;
}

float position (float velocity, float time)
{
    float distance = velocity * time; // Getting distance based on velocity and change in time
    return distance;
}

bool inBetween (float number, float lowerBound, float upperBound)
{
    bool numBetweenBounds = false;
    
    if ( (number >= upperBound) || (number <= lowerBound)) // If number is not between bounds, it will be true
    {
        numBetweenBounds = true;
    }
    
    return numBetweenBounds;
}
