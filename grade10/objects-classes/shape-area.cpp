// Linking following libraries
#include <iostream>
#include <cmath>

using namespace std;

// Declaring class
class Shape
{
private:
    float width; // Declaring private variables
    float height;
    double radius;
public:
    Shape (float wid, float hei) // Declaring constructor to get lengths for a rectangle
    {
        width = wid;
        height = hei;
    }
    
    Shape (float wid) // Declaring constructor to get the width of a square
    {
        width = wid;
    }
    
    Shape (double rad) // Declaring constructor to find the radius of a circle
    {
        radius = rad;
    }
    
    // Declaring functions to return areas of each respective areas
    float getRectArea ();
    float getSquareArea();
    float getCircArea();
};

// Declaring class for a rectangle
class Rectangle: public Shape
{
public:
    Rectangle (float wid, float  hei) : Shape(wid, hei) // Declaring constructor and linking to first Shape constructor
    {
        cout << endl;
        cout << "Area of rectangle: " << Shape :: getRectArea() << endl; // Returning area of the rectangle by linking it with the function of the Shape class
    }
};

// Declaring class for a square
class Square: public Shape
{
public:
    Square (float wid) : Shape (wid) // Declaring constructor and linking to second Shape constructor
    {
        cout << endl;
        cout << "Area of square: " << Shape :: getSquareArea() << endl; // Returning area of the square by linking it with the function of the Shape class
    }
};

// Declaring class for a circle
class Circle: public Shape
{
public:
    Circle (double rad) : Shape (rad) // Declaring constructor and linking to third Shape constructor
    {
        cout << endl;
        cout << "Area of circle: " << Shape :: getCircArea() << endl; // Returning area of the circle by linking it with the function of the Shape class
    }
};

int main()
{
    // Declaring variables
    char userChar;
    float userWidth, userHeight;
    double userRadius;
    
    // Getting the user decision and making sure it is valid
    do
    {
        cout << "If you would like to find the area of a circle, please enter 'c'. If you would like to find the area of a square, please enter 's'. If you would like to find the area of a rectangle, please enter 'r':";
        cin >> userChar;
    } while (userChar != 'c' && userChar != 'r' && userChar != 's');
    
    if (userChar == 'c') // If user wants to find the area of a circle
    {
        // Getting radius of the circle and making sure it is positive
        do
        {
            cout << "Please enter the radius of the circle: ";
            cin >> userRadius;
        } while (userRadius < 0);
        
        // Calling constructor to output area of square
        Circle shape(userRadius);
    }
    else if (userChar == 'r') // If user wants to find area of a rectangle
    {
        // Getting length and width of the rectangle and making sure it is positive
        do
        {
            cout << "Please enter the length and width of the rectangle: ";
            cin >> userHeight >> userWidth;
        } while (userHeight < 0 || userWidth < 0);
        
        // Calling constructor to output area of rectangle
        Rectangle shape(userWidth, userHeight);
    }
    else if (userChar == 's') // If user wants to find area of a square
    {
        // Getting side length of square and making sure it is positive
        do
        {
            cout << "Please enter the width of the square: ";
            cin >> userWidth;
        } while (userWidth < 0);
        
        // Calling constructor to output area of square
        Square shape(userWidth);
    }
    
    return 0;
}

// Function that returns area of circle
float Shape:: getCircArea()
{
    return 3.14 * pow(radius, 2);
}

// Function that returns area of square
float Shape:: getSquareArea()
{
    return pow(width, 2);
}

// Function that returns area of rectangle
float Shape:: getRectArea()
{
    return width * height;
}
