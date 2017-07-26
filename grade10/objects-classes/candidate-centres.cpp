#include <iostream>
#include <string>

using namespace std;

// Defining class TEST that has all member values as required by the program
class TEST
{
private:
    int testCode;
    string description;
    int noCandidate;
    int centersReqd;
    
    void calcntr() // Following equation as required
    {
        centersReqd = (noCandidate / 100) + 1 ;
        return;
    }
public:
    void schedule(); // Declaring function prototypes
    void disptest();
};

int main ()
{
    TEST center; // Declaring object and calling functions
    center.schedule();
    center.disptest();
}

// Getting values
void TEST:: schedule()
{
    cout << "Please enter the value for the test code: "; // Getting test code
    cin >> testCode;
    cin.ignore();
    
    cout << "Please enter a description: "; // Getting description
    getline(cin, description);
    
    cout << "Please enter the noCandidate value: "; // Getting noCandidate value
    cin >> noCandidate;
    
    calcntr(); // Calling private member function calcntr()
    
    return;
}

// Displaying values
void TEST:: disptest()
{
    cout << "-------------------" << endl;
    
    cout << "Test code: " << testCode << endl; // Displaying test code
    cout << "Description: " << description << endl; // Displaying description
    cout << "noCandidate: " << noCandidate << endl; // Displaying noCandidate
    cout << "Centers needed: " << centersReqd << endl; // Displaying number of noCandidate
    
    return;
}
