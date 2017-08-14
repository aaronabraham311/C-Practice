// Including all libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

// Declaring function
void fread();

int main()
{
   
    cout << "Number of characters in OUT.txt file: "; // Outputting number of alphabets in file
    fread(); // Calling function to count number of alphabets in file */
     
    return 0;
}

void fread()
{
    ifstream file ("OUT.txt"); // Creating object that links with OUT.txt file
    char fileMessage; // Declaring all pertinent variables
    int letterCount = -1;
    
    if (file.is_open()) // Making sure file is open
    {
        while (!file.eof()) // Creating loop that loops all characters of a file until the file ends
        {
            file >> fileMessage; // Putting charcter into variable
            
            if (isalpha(fileMessage)) // Increasing letter count if character is an alphabetic character
            {
                letterCount ++;
            }
            
        }
    }
    cout << letterCount << endl; // Outputting letter count
    file.close(); // Closing file
    
    return;
}
