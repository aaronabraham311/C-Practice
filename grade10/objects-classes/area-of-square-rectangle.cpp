#include <iostream>
using namespace std;

// Declaring pure virtual functions for getArea() and getPerimeter()
class IShape
{
public:
    virtual int getArea() = 0;
    virtual int getPerimeter() = 0;
};

class Rectangle : public IShape
{
private:
    int length; // Declaring variables for rectangle dimensions
    int width;
public:
    Rectangle (int l, int b) // Defining constructor to set the variables to certain values
    {
        length = l;
        width = b;
    }
    
    int getArea() // Defining function to find the area by multiplying the length and width
    {
        return length * width;
    }
    
    int getPerimeter() // Defining function to find the perimeter by multiplying the sum of length and width by 2
    {
        return 2 * (length + width);
    }
    
};

class Square : public IShape
{
private:
    int side; // Declaring variable for square dimensions
public:
    Square (int a) // Defining constructor to set the side dimension
    {
        side = a;
    }
    
    int getArea () // Defining a function to find the area of a square by multiplying the side by itself
    {
        return side * side;
    }
    
    int getPerimeter() // Defining a function to find the perimeter by multiplying the side by 4
    {
        return 4 * side;
    }
};

int main ()
{
    Rectangle rt(7, 4); // Setting default rectangle dimensions
    cout << "Area of rectangle: " << rt.getArea() << endl; // Outputting area of a rectangle
    cout << "Perimeter of rectangle: " << rt.getPerimeter() << endl; // Outputting perimeter of a rectangle
    
    cout << "********************************************" << endl;
    
    Square s(4); // Setting default square dimensions
    cout << "Area of square: " << s.getArea() << endl; // Outputting area of the square
    cout << "Perimeter of square: " << s.getPerimeter() << endl; // Outputting perimeter of the square
    
    return 0;
}
