#include <iostream>

using namespace std;

// Declaring class std_basic_info
class std_basic_info
{
private:
    char name[30]; // Making array for student's name
    int age; // Making variable for student's age
    char gender; // Making character for student's gender
public:
    void getBasicInfo (); // Initializing function to get information for private variables
    void putBasicInfo (); // Initializing function to display information for private variables
};

// Declaring class std_result_info, and publically inheriting std_basic_info class
class std_result_info: public std_basic_info
{
private:
    double markObtained, totalM; // Making variables for total marks and mark obtained by student
    double perc; // Making variable for percentage mark
    char grade; // Making variable for grade mark
public:
    void getResultInfo (); // Initializing function to get information for private variables
    void putResultsInfo (); // Initializing function to display information for private variables
};

int main ()
{
    // Declaring object
    std_result_info studentMarks;
    
    // Calling functions to get information
    studentMarks.getBasicInfo();
    studentMarks.getResultInfo();
    
    // Calling functions to display information
    studentMarks.putBasicInfo();
    studentMarks.putResultsInfo();
    
    return 0;
}

void std_basic_info:: getBasicInfo()
{
    // Getting student's name
    cout << "Please enter the name of the student: ";
    cin.getline(name, 30);
    
    // Getting age of student, and making sure age is valid
    do
    {
        cout << "Please enter the age of the student: ";
        cin >> age;
        
    } while (age < 0);
    
    // Getting gender of student, and making sure gender is valid
    do
    {
        cout << "Please enter the gender of the student (M/F): ";
        cin >> gender;
    } while (gender != 'M' && gender != 'F');
    
    return;
}

void std_result_info:: getResultInfo()
{
    // Getting total marks of the assessment, and making sure total marks is valid
    do
    {
        cout << "Please enter the total marks that can be achieved on the assesment: ";
        cin >> totalM;
    } while (totalM < 0);
    
    // Getting marks obtained on the assessment, and making sure marks is valid and not greater than the total marks
    do
    {
        cout << "Please enter the marks obtained by the student: ";
        cin >> markObtained;
    } while (markObtained < 0 || markObtained > totalM);
    
    perc = (markObtained / totalM) * 100; // Getting percentage
    
    // Getting grade based on percentage
    if (perc > 80 && perc <= 100)
    {
        grade = 'A';
    }
    else if (perc > 60 && perc <= 80)
    {
        grade = 'B';
    }
    else if (perc > 40 && perc <= 60)
    {
        grade = 'C';
    }
    else
    {
        grade = 'D';
    }
    
    return;
}

void std_basic_info:: putBasicInfo()
{
    cout << "****************************" << endl;
    
    cout << "Name of student: " << name << endl; // Outputting name

    cout << "Age of student: " << age << endl; // Outputting age
    
    // Outputting gender based on character
    cout << "Gender of student: ";
    
    if (gender == 'M')
    {
        cout << "Male" << endl;
    }
    else if  (gender == 'F')
    {
        cout << "Female" << endl;
    }
    
    return;
}

void std_result_info:: putResultsInfo()
{
    // Outputting mark
    cout << "Mark recieved: " << markObtained << '/' << totalM << endl;
    
    //Outputting percentage
    cout << "Percentage recieved: " << perc << "%" << endl;
    
    // Outputting grade
    cout << "Grade recieved: " << grade << endl;
}
