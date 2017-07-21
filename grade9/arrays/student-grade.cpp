#include <iostream>
using namespace std;

// Prototypes:
void printArray (float array[][3], int studentNumber);
void updateArray (float array[][3], float studentGrade, int row, int column);
void updateInitialArray (float array[][3], int studentNumber);
float studentAverage (float array[][3], int studentNumber);
float classAverage (float array[][3], int quizNumber, int studentNumber);

int main ()
{
    // Initializing variables
    int studentNumbers;
    int userRow, userColumn;
    float studentGrade;
    char userMarkChoice;
    char userStudentAverageChoice;
    char userClassAverageChoice;
    
    // Asks for number of students, and makes sure that number is not equal to or less than 0
    do
    {
        cout << "Please enter the number of students: " ;
        cin >> studentNumbers;
    } while (studentNumbers <= 0);
    
    // Initializes array
    float studentGrades [studentNumbers][3];
    
    // Updates array with all zeroes, and outputs zero array
    updateInitialArray (studentGrades, studentNumbers);
    printArray (studentGrades, studentNumbers);
    
    // Updates individual quiz marks while user agrees to
    do {
        // Gets student number
        cout << "Please enter the student number: " ;
        cin >> userRow;
        
        // If student number is invalid, program breaks
        if (userRow > studentNumbers || userRow <= 0)
            break;
        
        // Gets quiz number
        cout << "Please enter the quiz you would like to update: ";
        cin >> userColumn;
        
        // If quiz number is invalid, program breaks
        if (userColumn > 3 || userColumn <= 0)
            break;
        
        // Makes variables usable
        userRow --;
        userColumn --;
        
        // Getting student grade, and making sure it is valid
        do
        {
            cout << "Please enter the grade: ";
            cin >> studentGrade;
        } while (studentGrade < 0 || studentGrade > 100);
        
        // Updates and prints out array
        updateArray (studentGrades, studentGrade, userRow, userColumn);
        printArray (studentGrades, studentNumbers);
        
        // Asks user if user wants to input more marks
        do
        {
            cout << "Would you like to update more marks? If entered 'n', you may not enter any more marks. (y/n): ";
            cin >> userMarkChoice;
        } while ((userMarkChoice != 'y') && (userMarkChoice != 'n'));
        
    } while (userMarkChoice == 'y');
    
    // Creating infinite loop
    while (true)
    {
        int studentNumber;
        
        // Asks if user wants average of student. If not, program breaks
        do
        {
            cout << "Would you like the average score of a student? (y/n) ";
            cin >> userStudentAverageChoice;
        } while ((userStudentAverageChoice != 'y') && (userStudentAverageChoice != 'n'));
        
        if (userStudentAverageChoice == 'n')
            break;
        
        // Gets student number
        cout << "Please enter the student number: ";
        cin >> studentNumber;
        
        // If student number is not valid, program breaks
        if (studentNumber > studentNumbers || studentNumber <= 0)
            break;
        
        // Makes new variable used by average program
        int manipulatedStudentNumber = studentNumber - 1;
        
        // Outputs average of student
        cout << "The average of Student " << studentNumber << " is: " << studentAverage (studentGrades,manipulatedStudentNumber) << '%' << endl;
        
    }
    
    // Creating infinite loop
    while (true)
    {
        int quizNumber;
        
        // Asks if user wants class average. If not, program breaks
        do
        {
            cout << "Would you like the class average of a quiz? (y/n) ";
            cin >> userClassAverageChoice;
        } while ((userClassAverageChoice != 'y') && (userClassAverageChoice != 'n'));
        
        if (userClassAverageChoice == 'n')
            break;
        
        // Gets quiz number
        cout << "Please enter quiz number: ";
        cin >> quizNumber;
        
        // If quiz number is invalid, program breaks
        if (quizNumber > 3 || quizNumber <= 0)
            break;
        
        // Creates variable used by class average program
        int manipulatedQuizNumber = quizNumber - 1;
        
        // Outputs class average
        cout << "The class average of quiz " << quizNumber << " is: " << classAverage (studentGrades, manipulatedQuizNumber, studentNumbers) << '%' << endl;
    }
    
    // Outputs final message
    cout << "Program has finished either due to your decision or invalid input. " << endl;
    
    return 0;
}

// Prints array
void printArray (float array[][3], int studentNumber)
{
    for (int row = 0; row < studentNumber; row ++)
    {
        cout << "Student " << row + 1 << ": ";
        for (int column = 0; column < 3; column ++)
        {
            cout << array[row][column] << " ";
        }
        cout << endl;
    }
    
    return;
}

// Updates array based on student grade
void updateArray (float array[][3], float studentGrade, int row, int column)
{
    
    array[row][column] = studentGrade;
    
    return;
}

// Updates initial array into zero
void updateInitialArray (float array[][3], int studentNumber)
{
    for (int row = 0; row < studentNumber; row ++)
    {
        for (int column = 0; column < 3; column ++)
        {
            array[row][column] = 0;
        }
    }
}

// Calculates student average
float studentAverage (float array[][3], int studentNumber)
{
    float sum = 0;
    
    // Finds grade sum of all quizzes for student by changing column, not row
    for (int column = 0; column < 3; column ++)
    {
        sum += array[studentNumber][column];
    }
    
    // Returns average (sum of quiz grades / number of quizzes)
    return sum / 3;
}

// Calculates class average
float classAverage (float array[][3], int quizNumber, int studentNumber)
{
    float sum = 0;
    
    // Finds grade sum of all students in class by changing row, instead of column
    for (int row = 0; row < studentNumber; row ++)
    {
        sum += array[row][quizNumber];
    }
    
    // Returns class average (sum of quiz grades / number of students in class)
    return sum / studentNumber;
}
