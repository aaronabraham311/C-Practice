#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream equationFile;
    equationFile.open("y=mx+b.txt");
    
    float userSlope, userYintercept;
    
    cout << "Please enter the slope of the equation: ";
    cin >> userSlope;
    
    cout << "Please enter the y-intercept of the equation: ";
    cin >> userYintercept;
    
    for (int xCord = -5; xCord <= 5; xCord ++)
    {
        equationFile << xCord << "\t" << xCord * userSlope + userYintercept << endl;
    }
    
    equationFile.close();
    return 0;
}
