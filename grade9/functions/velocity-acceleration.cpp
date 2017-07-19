#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Declaring variables
    float userVelocity, userTime, userAcceleration;
    float userDistance = 0;
    float currentTime = 0;
    float changeInTime = 0.1;
    
    // Setting up file
    ofstream objectDistance;
    objectDistance.open("Distance of Object.txt");
    
    // Getting velocity, time and acceleration from user
    cout << "Please enter the velocity of the object: ";
    cin >> userVelocity;
    
    cout << "Please enter the time at which you would like to see the total distance of the object: " ;
    cin >> userTime;
    
    cout << "Please enter the acceleration of the object: " ;
    cin >> userAcceleration;
    
    objectDistance << "Time" << "\t" << "Distance" << endl;
    objectDistance << 0.0 << "\t" << 0.0 << endl;
    
    // Updating values for time, velocity (based on acceleration) and distance
    while (currentTime <= userTime)
    {
        userDistance = userDistance + (userVelocity * changeInTime);
        currentTime += changeInTime;
        userVelocity = userVelocity + (userAcceleration * changeInTime);
        objectDistance << currentTime << "\t" << userDistance << endl;
    }
    
    objectDistance.close();
    
    return 0;
}
