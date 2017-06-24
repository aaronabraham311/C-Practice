#include <iostream>

using namespace std;

int main()
{
    int cows, chickens; // Initializing variable
    
    cout<<"Please enter the amount of cows: "; // Getting number of cows
    cin>>cows;
    
    cout<<"Please enter the amount of chickens: "; // Getting number of chickens
    cin>>chickens;
   
    int cowLegs= 4*cows; // Finding number of legs of cows
    int chickenLegs= 2*chickens; // Finding number of legs of chickens
    
    cout<<"The amount of total legs is: "<< cowLegs+chickenLegs << endl; // Outputting sum
    
    return 0;
}
