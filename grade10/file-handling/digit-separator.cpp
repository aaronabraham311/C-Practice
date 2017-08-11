// Including all pertinent libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    // Creating objects and linking to respective files
    ifstream inputFile ("text1.txt");
    ofstream digitFile ("DIGIT.txt");
    ofstream nonDigitFile ("NONDIG.txt");
    char temporaryChar;
    
    while (!inputFile.eof()) // Running loop until end of file
    {
        temporaryChar = inputFile.get(); // Getting character
        
        // Puts character into digit file if it is a digit
        if (isdigit(temporaryChar))
        {
            digitFile << temporaryChar;
        }
        else // Will put rest of characters into non-digit file
        {
            nonDigitFile << temporaryChar << endl;
        }
    }
    
    // Closing files
    inputFile.close();
    digitFile.close();
    nonDigitFile.close();
    
    return 0;
}
