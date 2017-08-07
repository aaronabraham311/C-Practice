// Declaring all libraries
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Declaring all variables
    char name[20];
    char word [100];
    string word1;
    int numberStudents;
    int elaMarks;
    int scienceMarks;
    int mathMarks;
    double average;
    int studentID;
    
    ofstream file1 ("realMarks.txt"); // Making an object to store data
    
    // Getting a valid number of students
    do
    {
        cout << "Please enter the number of students in the class: ";
        cin >> numberStudents;
    } while (numberStudents <= 0);
    
    // Ends program if there are no students
    if (numberStudents == 0)
    {
        cout << "Have a good day. " << endl;
    }
    else
    {
        for (int i = 0; i < numberStudents; i ++)
        {
            cout << "Entering the marks for Student " << i + 1 << ':' << endl;
            
            do // Getting valid student ID number
            {
                cout << "Please enter the student ID: ";
                cin >> studentID;
            } while (studentID < 0);
            
            // Getting name of student
            cout << "Please enter the name of student: ";
            cin >> name;
            
            // Getting valid math mark
            do
            {
                cout << "Please enter the math mark: ";
                cin >> mathMarks;
            } while (mathMarks < 0 || mathMarks > 100);
            
            // Getting valid ELA mark
            do
            {
                cout << "Please enter the ELA mark: ";
                cin >> elaMarks;
            } while (elaMarks < 0 || elaMarks > 100);
            
            // Getting valid science mark
            do
            {
                cout << "Please enter the science mark: ";
                cin >> scienceMarks;
            } while (scienceMarks < 0 || scienceMarks > 100);
            
            average = (mathMarks + scienceMarks + elaMarks)/3; // Getting average mark
            
            file1 << "Student Name: " << name << " | Student Average: " << average << "%" << endl; // Outputting data to file
        }
    }
    
    file1.close();
    
    // Making new objects to copy one file into another
    ifstream rewriteInput ("realMarks.txt");
    ofstream rewriteOutput ("realMarks_copy.txt");
 
    // Will run until end of the file
    while(!rewriteInput.eof())
    {
        rewriteInput >> word; // Getting word
        
        // Checking if word is average and average is below 45%
        if( ( (word[0] == '0') || (word[0] == '1') || (word[0] == '2') || (word[0] == '3') || (word[0] == '4') || (word[0] == '5') || (word[0] == '6') || (word)[0] == '7') || (word[0] == '8') || (word[0] == '9') && ((word[1] == '%')) || ( ((word[0] == '1') || (word[0] == '2') || (word[0] == '3')) && ((word[1] == '0') || (word[1] == '1') || (word[1] == '2') || (word[1] == '3') || (word[1] == '4') || (word[1] == '5') || (word[1] == '6') || (word[1] == '7') || (word[1] == '8') || (word[1] == '9'))) || (((word[0] == '4') && ((word[1] = '0') || (word[1] = '1') || (word[1] == '2') || (word[1] == '3') || (word[1] == '4'))) ) )
        {
            word[0] = ' ';
            word[1] = ' ';
            cout << "The student's average was below 45%. Please enter the student's new ELA mark, math mark, and science mark: ";
            cin >> elaMarks >> mathMarks >> scienceMarks; // Getting new marks
            rewriteOutput << (elaMarks + mathMarks + scienceMarks) / 3 << "% " << endl; // Outputting average
        }
        else
        {
            rewriteOutput << word << " "; // Will output characters otherwise
        }
    }
    
    rewriteInput.close();
    rewriteOutput.close();
    
    // Copying contents of copy file into real file
    ifstream finalInput ("realMarks_copy.txt");
    ofstream finalOutput ("realMarks.txt");
    
    // Will run loop until end of file
    while (!finalInput.eof())
    {
        getline(finalInput, word1); // Getting whole line and putting it into file.
        finalOutput << word1 << " " << endl;
    }
    
    return 0;
}
