// Including all libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
  // Declaring variables and opening text file in directory
    string name;
    int mark, studentProfiles;
    ofstream file ("marks.txt");
    
    // Getting number of student profiles, and making sure it is greater than or equal to 0
    do
    {
        cout << "Please enter the number of student profiles you would like to make: ";
        cin >> studentProfiles;
    } while (studentProfiles <= 0);
    
    
    if (studentProfiles != 0) // Only continuing program if the number of student profiles is greater than 0
    {
        cout << "Please input the name and the marks of the student: " << endl;
        
        while (studentProfiles != 0) // Inputs data into file until there are no more student profiles
        {
            cin >> name >> mark; // Getting name and mark
            file << "Name: " << name << "\t Mark: " << mark << endl; // Writing data into file
            studentProfiles --; // Decreasing number of profiles by one every time loop is run
        }
        
    }
    
    file.close(); // Closing file
    return 0;
}
