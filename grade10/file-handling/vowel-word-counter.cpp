// Including all pertinent libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    ifstream file ("ABC.txt"); // Creating ifstream object that is linked with ABC.txt
    char temporaryChar;
    int wordCount = 0;
    
    for (int i = 0; !file.eof(); i ++) // Running loop until end of file
    {
        temporaryChar = file.get(); // Getting character and converting to lower case
        islower(temporaryChar);
        
        if (temporaryChar == ' ') // Counting words if it preceded by spaces
        {
            temporaryChar = file.get();  // Getting next character and converting to lower case
            islower(temporaryChar);
            
            // Increasing counter if character is vowel
            if (temporaryChar == 'a' || temporaryChar == 'e' || temporaryChar == 'i' || temporaryChar == 'o'|| temporaryChar == 'u')
            {
                wordCount ++;
            }
        }
        
        else if (i == 0) // Doing same procedure for first word
        {
            if (temporaryChar == 'a' || temporaryChar == 'e' || temporaryChar == 'i' || temporaryChar == 'o'|| temporaryChar == 'u')
            {
                wordCount ++;
            }
        }
    }
    
    cout << "There are " << wordCount << " words that begin with a vowel." << endl; // Outputting number of vowel words
    
    file.close(); // Closing file
    
    return 0;
}
