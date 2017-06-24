#include <iostream>
#include <string>

using namespace std;

int main()
{
    string fullName;
    
    cout<<"Please enter your full name: ";
    getline(cin,fullName);
    
    char firstInitial= fullName.at(0);
    
    int spaceIndex= fullName.find(" ");
    
    char lastInitial= fullName.at(spaceIndex + 1);
    
    cout<<"The initials of your name is: "<<firstInitial<<"."<<lastInitial<<endl;
    
    return 0;
}
