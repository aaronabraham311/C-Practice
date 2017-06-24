#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int leg1; // Declaring variables for 3 sides of triangle
    int leg2;
    int hypotenuse;
    
    cout<<"Please enter the length of one leg: "; // Getting length of one side of triangle
    cin>>leg1;
    
    cout<<"Please enter the length of the hypotenuse: "; // Getting length of hypotenuse of triangle
    cin>>hypotenuse;
    
    leg2= sqrt(pow(hypotenuse, 2)- pow(leg1,2)); // Finding length of Leg 2 by using (hypotenuse)^2 - a^2
    
    cout<<"The value of the remaining leg is: "<<leg2<<endl; // Outputting value of Leg 2
    
    return 0;
}
