#include <fstream>
#include <iostream>

using namespace std;

// Prototypes
float xcoordinate (float, float);
float ycoordinate (float, float);

int main ()
{
    
    // Initialzing and getting values of variables
    float velocityX, velocityY, userInitialPositionX, userInitialPositionY, outXcoordinate, outYcoordinate;
    float objectTime = 0;
    float changeInTime = 0.1;
    
    // Setting up file
    ofstream object2DFile;
    object2DFile.open("object2DFile.txt");
    object2DFile << "X-coordinate" << "\t" << "Y-coordinate" << endl;
   
    cout << "Please enter the x-coordinate of the initial position of the object: ";
    cin >> userInitialPositionX;
    
    cout << "Please enter the y-coordinate of the initial position of the object: ";
    cin >> userInitialPositionY;
    
    cout << "Please enter the x-cooordinate velocity of the object: ";
    cin >> velocityX;
    
    cout << "Please enter the y-coordinate velocity of the object: ";
    cin >> velocityY;
    
    outXcoordinate = userInitialPositionX;
    outYcoordinate = userInitialPositionY;
    
    while (objectTime <= 5)
    {
        outXcoordinate += xcoordinate (velocityX, changeInTime);
        outYcoordinate += ycoordinate (velocityY, changeInTime);
        
        object2DFile << outXcoordinate << "\t" << outYcoordinate << endl;
        objectTime += changeInTime;
    }
    
    object2DFile.close();
    return 0;
    
}

float xcoordinate (float velocityX, float time)
{
    
    float distance = velocityX * time; // Getting distance based on velocity and change in time
    return distance;
}

float ycoordinate (float velocityY, float time)
{
    
    float distance = velocityY * time; // Getting distance based on velocity and change in time
    return distance;
}
