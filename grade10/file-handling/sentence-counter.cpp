// Including all pertinent libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    ifstream file ("STORY.txt"); // Creating ifstream object and linking it to file
    char temporaryCharacter;
    int count = 0;
    
    while (!file.eof()) // Running loop until end of file
    {
        temporaryCharacter = file.get(); // Getting character
        
        if (temporaryCharacter == '.' || temporaryCharacter == '!' || temporaryCharacter == '?') // Checking if character is sentence terminator, and increasing counter if so
        {
            count ++;
        }
    }
    
    cout << "There are " << count << " sentences in the file."; // Outputting counter
    
    file.close(); // Closing file
    
    return 0;
}
