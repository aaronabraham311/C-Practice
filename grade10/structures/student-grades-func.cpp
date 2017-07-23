#include <iostream>
#include <string>

using namespace std;

struct student // Structure with namae, roll number, average, and marks
{
    string firstName, lastName;
    int rollNo, average;
    float studentMark;
};

// Function prototypes
void displayInfo (student studentArray[]);
void editInfo (student studentArray[]);

int main ()
{
    student students[5];
    
    for (int counter = 0; counter < 5; counter ++)
    {
        cout << "Please enter the roll number of the student: "; // Getting roll number of student
        cin >> students[counter].rollNo;
        
        cout << "Please enter the first name of the student: "; // Getting first name of student
        cin >> students[counter].firstName;
        
        cout << "Please enter the last name of the student: "; // Getting last name of student
        cin >> students[counter].lastName;
        
        cout << "Please enter the mark of the student: "; // Getting mark of student
        cin >> students[counter].studentMark;
        
        cout << endl;
    }
    
    displayInfo (students);
    editInfo (students);
    
    return 0;
}

void displayInfo (student studentArray[]) // Displays structure values
{
    cout << "--------------------------------------------" << endl << "The following is all the information of the students: " << endl;
    
    for (int counter = 0; counter < 5; counter ++) // Outputting roll number, first name, last name, and student mark
    {
        cout << "Roll Number: " << studentArray[counter].rollNo << endl;
        cout << "First Name: " << studentArray[counter].firstName << endl;
        cout << "Last Name: " << studentArray[counter]. lastName << endl;
        cout << "Mark: " << studentArray[counter].studentMark << endl;
        
        cout << endl;
    }
    
    return;
}

void editInfo (student studentArray[]) // Edits information
{
    // Declaring variables
    char answer;
    int studentNum;
    
    cout << "--------------------------------------------" << endl;
    
    do
    {
        cout << "Would you like to edit the information (please enter y or n): ";
        cin >> answer;
    } while (answer != 'y' && answer != 'n'); // Asking user if info wants to be edited, and making sure it is 'y' or 'n'
    
    do
    {
        do
        {
            cout << "Please enter the roll number (1, 2, 3, 4, 5): ";
            cin >> studentNum;
        } while (studentNum > 5 || studentNum < 0); // Asking user for roll number, and making it sure it is valid
        
        cout << "First Name: " << studentArray[studentNum - 1].firstName << endl; // Outputting first name
        
        do
        {
            cout << "Would you like to change the first name (y/n): ";
            cin >> answer;
        } while (answer != 'y' && answer != 'n'); // Asking user if change needed, and making sure response is valid
        
        if (answer == 'y') // If user wants to change first name, gives ability to change value
        {
            cout << "First Name: ";
            cin >> studentArray[studentNum - 1].firstName;
        }
        
        cout << "Last Name: " << studentArray[studentNum - 1].lastName << endl; // Outputting last name
        
        do
        {
            cout << "Would you like to change the last name (y/n): ";
            cin >> answer;
        } while (answer != 'y' && answer != 'n'); // Asking user if change needed, and making sure response is valid
        
        if (answer == 'y') // If user wants to change last name, gives ability to change value
        {
            cout << "Last Name: ";
            cin >> studentArray[studentNum - 1].lastName;
        }
        
        cout << "Mark: " << studentArray[studentNum - 1].studentMark << endl; // Outputting mark
        
        do
        {
            cout << "Would you like to change the mark (y/n): ";
            cin >> answer;
        } while (answer != 'y' && answer != 'n'); // Asking user if change needed, and making sure response is valid
        
        if (answer == 'y') // If user wants to change mark, gives ability to change value
        {
            cout << "Mark: ";
            cin >> studentArray[studentNum - 1].studentMark;
        }
        
        displayInfo(studentArray); // Displays info again
        
        do
        {
            cout << "Would you like to edit the information again (y/n): ";
            cin >> answer;
        } while (answer != 'y' && answer != 'n'); // Asks user if they want to edit info again, and sanitizing response
    } while (answer == 'y'); // Will repeat again if user want to
    
    return;

   }
