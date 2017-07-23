#include <iostream>
#include <string>
using namespace std;

struct marks // Structure for 3 marks
{
    float subject1, subject2, subject3;
};

struct student // Structure with namae, roll number, average, and marks
{
    string name;
    int rollNo, average;
    marks studentMark;
};

int main()
{
    student students[15]; // Declaring student array
    string studentNames[15]; // Declaring name array
    int studentAverages[15]; // Declaring average array
    
    for (int counter = 0; counter < 15; counter ++)
    {
        cout << "Please enter the name of the student: "; // Getting name of student (both first and last name)
        getline(cin,students[counter].name);
        
        studentNames[counter] = students[counter].name; // Entering name into name array
        
        cout << "Please enter the roll number of the student: "; // Getting roll number of student
        cin >> students[counter].rollNo;
        
        cout << "Please enter the marks of the student in 3 subjects: "; // Getting marks of student
        cin >> students[counter].studentMark.subject1 >> students[counter].studentMark.subject2 >> students[counter].studentMark.subject3;
        
        cout << endl;
        cin.ignore(100, '\n'); // Ignoring '\n' character
    }
    
    for (int counter = 0; counter < 15; counter ++) // Getting averages and inputting into average array
    {
        students[counter].average = (students[counter].studentMark.subject1 + students[counter].studentMark.subject2 + students[counter].studentMark.subject3) / 3;
        studentAverages[counter] = students[counter].average;
    }
    
    for (int counter1 = 0; counter1 < 15; counter1 ++) // Using bubble sort algorithim
    {
        for (int counter = 0; counter < 14; counter ++)
        {
            if (studentAverages[counter] < studentAverages[counter + 1]) // Compares if value is greater than array value above it
            {
                int averageTransfer = studentAverages[counter]; // If average is higher, will switch averages
                studentAverages[counter] = studentAverages[counter + 1];
                studentAverages[counter + 1] = averageTransfer;
                    
                string nameTransfer = studentNames[counter]; // If average is higher, will switch names
                studentNames[counter] = studentNames[counter + 1];
                studentNames[counter + 1] = nameTransfer;
            }
            
        }
    }
    
    
    cout << "The order of students in the class is: " << endl;
    
    for (int counter = 0; counter < 15; counter ++) // Outputting average array and name array simultaneously
    {
        cout << "Name: " << studentNames[counter] << endl;
        cout << "Average: " << studentAverages[counter] << endl;
    }
    
    return 0;
}
