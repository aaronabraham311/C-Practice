// Declaring libararies
#include <iostream>
#include <string>
#include <vector> // Using <vector> libarary to declare variable length array

using namespace std;

// Declaring Student class
class Student
{
protected:
    int studentNumber, studentClass; // Establishing variables for number, class, and name
    string studentName;
public:
    void getDetails (); // Declaring function to input into above variables
};

class Wardrobe: public Student
{
private:
    int shirts, pants, socks; // Declaring variables to store number of shirts, pants and socks
public:
    void getWardrobe (); // Function to input above variables
    int calculateClothes (); // Function to calculate total number of clothes
    void display (); // Function to display number of clothes and total
};

int main ()
{
    int numberOfStudents; // Declaring variable to store number of students in program
    
    cout << "Welcome to the wardrobe program. " << endl; // Welcome message
    
    // Getting number of students, and validating results (making sure it is greater than of equal to zero)
    do
    {
        cout << "Please enter the number of students: ";
        cin >> numberOfStudents;
    } while (numberOfStudents < 0);
    
    // Runs rest of program if there is more than 0 students in the class
    if (numberOfStudents > 0)
    {
        vector <Wardrobe> wardrobe (numberOfStudents); // Declaring a vector array to store information for all students
        
        // Running a loop and calculating information for each student
        for (int i = 0; i < numberOfStudents; i ++)
        {
            cout << "***********************" << endl;
            cout << "Please enter the following information for Student " << i + 1 << endl;
            
            // Calling functions as declared in the class: gets student's detail, his/her's clothes, and displays values
            wardrobe[i].getDetails();
            wardrobe[i].getWardrobe();
            wardrobe[i].display();
        }
    }
    
    cout << "Have a good day! " << endl; // End message
    
    
    return 0;
}

// NOTE: ORGANIZED ALPHABETICALLY

int Wardrobe:: calculateClothes()
{
    return (shirts + pants + socks); // Returns total number of clothes
}

void Wardrobe:: display()
{
    // Displaying all information collected by program
    cout << "Name: " << studentName << endl;
    cout << "Number: " << studentNumber << endl;
    cout << "Class: " << studentClass << endl;
    cout << "Shirts: " << shirts << endl;
    cout << "Pants: " << pants << endl;
    cout << "Socks: " << socks << endl;
    cout << "Total: " << calculateClothes() << endl;
    
    return;
}

void Student:: getDetails()
{
    // Getting student's number
    cout << "Please enter the student's number: ";
    cin >> studentNumber;
    
    // Getting student's class
    cout << "Please enter the student's class: ";
    cin >> studentClass;
    
    // Getting student's name
    cout << "Please enter the student's name: ";
    cin.ignore();
    getline (cin, studentName);
    
    return;
}

void Wardrobe:: getWardrobe()
{
    // Getting number of shirts and validating results
    do
    {
        cout << "Please enter the number of shirts: ";
        cin >> shirts;
    } while (shirts < 0);
    
    // Getting number of pants and validating results
    do
    {
        cout << "Please enter the number of pants: ";
        cin >> pants;
    } while (pants < 0);
    
    // Getting number of socks and validating results
    do
    {
        cout << "Please enter the number of socks: ";
        cin >> socks;
    } while (socks < 0);
    
    return;
}
