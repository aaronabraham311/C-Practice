#include <iostream>

using namespace std;

// Making class with all requirements
class Student
{
private:
    int admno;
    char sname[20];
    float eng, science, math;
public:
    void Takedata();
    float ctotal ();
    void Showdata ();
};


int main ()
{
    Student studentInfo; // Making object
    
    // Calling functions
    studentInfo.Takedata();
    studentInfo.ctotal();
    studentInfo.Showdata();
}

// Function gets data from user
void Student:: Takedata()
{
    cout << "Please enter the student's admno: "; // Getting admno
    cin >> admno;
    cin.ignore(); // Ignoring null character
    
    cout << "Please enter the name: "; // Getting name with gets()
    gets(sname);
    
    do
    {
        cout << "Please enter the math mark: "; // Getting math mark and sanitizing data
        cin >> math;
    } while (math < 0 || math > 100);
    
    do
    {
        cout << "Please enter the science mark: "; // Getting science mark and sanitizing data
        cin >> science;
    } while (science < 0 || science > 100);
    
    do
    {
        cout << "Please enter the English mark: "; // Getting English mark and sanitizing data
        cin >> eng;
    } while (eng < 0 || eng > 100);
    
    return;
}

// Function returns total of all marks
float Student:: ctotal()
{
    float total = eng + science + math; // Adding all marks and returning
    return total;
}

// Outputting data
void Student:: Showdata()
{
    cout << "---------------------------------" << endl;
    
    cout << "Student's admno: " << admno << endl; // Outputting admno
    cout << "Name: ";
    puts(sname); // Outputting name
    
    // Outputting all marks
    cout << "Student's English mark: " << eng << endl;
    cout << "Student's Math mark: " << math << endl;
    cout << "Student's Science mark: " << science << endl;;
    
    return;
}
