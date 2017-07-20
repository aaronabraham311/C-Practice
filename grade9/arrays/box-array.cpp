#include <iostream>
#include <fstream>

//Functions
//betweenBounds determines whether the particle is between the bounds (walls)
bool betweenBound(float lower, float upper, float pos);
//deltaD determines the distance the object travels in the time increment
float deltaD(float velocity, float deltaT);
//positionUpdate updates the positions and velocities based on previous two functions
void positionUpdate(float positions[], float verticalwalls[], float horizontalwalls[], float deltaT, float velocity[], int spaces);

using namespace std;

int main()
{
    //making arrays for variables
    /*
     ****************************
     position[0] = x-coordinate
     position[1] = y-coordinate
     velocity[0] = x-velocity
     velocity[1] = y-velocity
     verticalWalls[0] = left wall
     verticalWalls[1] = right wall
     horizontalWalls[0] = bottom wall
     horizaontalWalls[1] = top wall
     ****************************
     */
    
    float positions[2];
    float velocity[2];
    float verticalWalls[2];
    float horizontalWalls[2];
    
    // making variables for total time of simulation and change in time
    float time, deltaT;
    
    //opening file
    ofstream graph;
    graph.open("graphPoints.txt");
    
    //get the wall positions, ensuring that the box is well-formed
    do
    {
        cout << "Please enter valid positions for the left and right walls: ";
        cin >> verticalWalls[0] >> verticalWalls[1];
    } while(verticalWalls[0] >= verticalWalls[1]);
    
    
    do
    {
        cout << "Please enter valid positions for the lower and upper walls: ";
        cin >> horizontalWalls[0] >> horizontalWalls[1];
    } while(horizontalWalls[0] >= horizontalWalls[1]);
    
    //get the position of the particle. Make sure that the particle starts inside the box!
    do
    {
        cout << "Please enter the x coordinate of the particle (it must be inside the box): ";
        cin >> positions[0];
    }while(positions[0] >= verticalWalls[1] || positions[0] <= verticalWalls[0]);
    
    
    do
    {
        cout << "Please enter the y coordinate of the particle (it must be inside the box): ";
        cin >> positions[1];
    }while(positions[1] >= horizontalWalls[1] || positions[1] <= horizontalWalls[0]);
    
    //get the velocity
    cout << "Please enter the velocity in the x direction then the velocity in the y direction: ";
    cin >> velocity[0] >> velocity[1];
    
    //get the time
    cout << "Please enter the amount of time you would like to simulate the particle: ";
    cin >> time;
    
    //get the time interval
    cout << "Please enter the time interval: ";
    cin >> deltaT;
    
    //making loop that runs untill current time reaches final time of simulation
    for(float t = 0; t < time; t += deltaT)
    {
        //updates all positions and velocities in respective arrays
        positionUpdate(positions, verticalWalls, horizontalWalls, deltaT, velocity, 2);
        
        //write to file
        graph << positions[0] << '\t' << positions[1] << endl;
    }
    
    return 0;
}
//decides if pos is between lower and upper. Returns true if yes, false if no
bool betweenBound(float lower, float upper, float pos)
{
    if(pos <= lower || pos >= upper)
        return false;
    return true;
}
//calculates the distance travelled by a particle
float deltaD(float velocity, float deltaT)
{
    return velocity * deltaT;
}

void positionUpdate(float positions[], float verticalwalls[], float horizontalwalls[], float deltaT, float velocity[], int spaces)
{
    //Change the velocity based on whether the particle is out of the box and in which direction
    for (int index = 0; index < spaces; index++)
    {
        if (index == 0)
        {
            if (betweenBound(verticalwalls[0], verticalwalls[1], positions[index]) == false)
                velocity[index] *= -1;
        }
        else if (index == 1)
        {
            if (betweenBound(horizontalwalls[0], horizontalwalls[1], positions[index]) == false)
                velocity[index] *= -1;
        }
        
        //updates position based on velocity and change in time
        positions[index] += deltaD(velocity[index], deltaT);

    }
    
    return;
}
