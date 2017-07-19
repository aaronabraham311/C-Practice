#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    // Setting up variables for getting the x and y coordinates for 5 points and user's answer
    float point1x, point1y, point2x, point2y, point3x, point3y, point4x, point4y, point5x, point5y;
    char userRedo;
    
    do // Making do-while loop so that user can redo points if they are wrong
    {
        cout << "Please enter the x-coordinate for Point 1: "; // Getting input for x and y coordinates
        cin >> point1x;
        
        cout << "Please enter the y-coordinate for Point 1: ";
        cin >> point1y;
        
        cout << "Please enter the x-coordinate for Point 2: ";
        cin >> point2x;
        
        cout << "Please enter the y-coordinate for Point 2: ";
        cin >> point2y;
        
        cout << "Please enter the x-coordinate for Point 3: ";
        cin >> point3x;
        
        cout << "Please enter the y-coordinate for Point 3: ";
        cin >> point3y;
        
        cout << "Please enter the x-coordinate for Point 4: ";
        cin >> point4x;
        
        cout << "Please enter the y-coordinate for Point 4: ";
        cin >> point4y;
        
        cout << "Please enter the x-coordinate for Point 5: ";
        cin >> point5x;
        
        cout << "Please enter the y-coordinate for Point 5: ";
        cin >> point5y;
    
        cout << "Point 1 has the coordinates of: (" << point1x << "," << point1y << ")" << endl;
        cout << "Point 2 has the coordinates of: (" << point2x << "," << point2y << ")" << endl;
        cout << "Point 3 has the coordinates of: (" << point3x << "," << point3y << ")" << endl;
        cout << "Point 4 has the coordinates of: (" << point4x << "," << point4y << ")" << endl;
        cout << "Point 5 has the coordinates of: (" << point5x << "," << point5y << ")" << endl;
        cout << "Are these points correct? If so, please press 'y' and if these points are not correct, please press 'n': ";
        cin >> userRedo;
    } while ( userRedo == 'n');
    
    // Using formula to find distances between the points
    float point1point2 = sqrt (pow(point2x - point1x, 2) + pow(point2y - point1y, 2));
    float point2point3 = sqrt (pow(point3x - point2x, 2) + pow(point3y - point2y, 2));
    float point3point4 = sqrt (pow(point4x - point3x, 2) + pow(point4y - point3y, 2));
    float point4point5 = sqrt (pow(point5x - point4x, 2) + pow(point5y - point4y, 2));
    float point1point5 = sqrt (pow(point5x - point1x, 2) + pow(point5y - point1y, 2));
    float point1point3 = sqrt (pow(point3x - point1x, 2) + pow(point3y - point1y, 2));
    float point2point5 = sqrt (pow(point2x - point5x, 2) + pow(point2y - point5y, 2));
    float point2point4 = sqrt (pow(point2x - point4x, 2) + pow(point2y - point5y, 2));
    float point1point4 = sqrt (pow(point4x - point1x, 2) + pow(point4y - point1y, 2));
    float point3point5 = sqrt (pow(point3x - point5x, 2) + pow(point3y - point5y, 2));
    
    //Outputting distances:
    cout << "The distance between Point 1 and Point 2 is: " << point1point2 << endl;
    cout << "The distance between Point 1 and Point 3 is: " << point1point3 << endl;
    cout << "The distance between Point 1 and Point 4 is: " << point1point4 << endl;
    cout << "The distance between Point 1 and Point 5 is: " << point1point5 << endl;
    cout << "The distance between Point 2 and Point 3 is: " << point2point3 << endl;
    cout << "The distance between Point 2 and Point 4 is: " << point2point4 << endl;
    cout << "The distance between Point 2 and Point 5 is: " << point2point5 << endl;
    cout << "The distance between Point 3 and Point 4 is: " << point3point4 << endl;
    cout << "The distance between Point 3 and Point 5 is: " << point3point5 << endl;
    cout << "The distance between Point 4 and Point 5 is: " << point4point5 << endl;
    
    return 0;
}

