#include <iostream>
#include <string>

using namespace std;

int main()
{
    string firstName;
    string lastName;
    
    cout<<"Please enter your first name: ";
    getline (cin, firstName);
    
    cout<<"Please enter your last name: ";
    getline (cin, lastName);
    
    cout<<"Your full name is: "<<firstName + " "+ lastName<<endl;
    
    cout<<"The first character of your name is: "<< firstName.at(0)<<endl;
    
    cout<<"The hyphenated version of your name is: "<< firstName + "-" + lastName<<endl;
    
    return 0;
}
