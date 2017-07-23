#include <iostream>
#include <string>

using namespace std;

struct studentMark // Structure for 3 marks
{
    int math, science, english;
};

struct classroom // Structure for name, roll number, marks
{
    string name;
    int studentNumber;
    studentMark marks;
};

int main ()
{
    classroom student[5]; // Declaring 5 student array to input relevant information
    
    for (int counter = 0; counter < 5; counter ++) // Gets name and roll number for each student
    {
        cout << "Please enter the name of the student, followed by the number: "; // Gets name and number
        cin >> student[counter].name >> student[counter].studentNumber;
        
        cout << "Please enter the marks of the student in order of Math, Science and English: "; // Gets marks
        cin >> student[counter].marks.math >> student[counter].marks.science >> student[counter].marks.english;

    }
    
    cout << "The students that have two subjects or more that are less than 60 are: " << endl;
    
    // Running loop in structure to find marks below 60
    for (int counter = 0; counter < 5; counter ++)
    {
        int markCount = 0; // Declaring mark counter
        if (student[counter].marks.math < 60) // Mark counter will increment if subject is less than 60
        {
            markCount++;
        }
        if (student[counter].marks.science < 60) // Mark counter will increment if subject is less than 60
        {
            markCount++;
        }
        if (student[counter].marks.english < 60) // Mark counter will increment if subject is less than 60
        {
            markCount++;
        }
        if (markCount >= 2) // If mark counter is greater than 2, then will output name
        {
            cout << student[counter].name << endl;
        }
    }
    
    return 0;
}
