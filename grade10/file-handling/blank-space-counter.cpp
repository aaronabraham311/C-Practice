// Including all pertinent libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
  ifstream file ("MYbook.txt"); // Linking object with file and declaring variables
    char fileCharacter;
    int count = 0;
    
    while (!file.eof()) // Runs loop through file until end of file
    {
        fileCharacter = file.get(); // Reads character into variable
        
        if (fileCharacter == ' ') // Increases counter if character is space
        {
            count ++;
        }
    }
    
    cout << "Number of blank spaces in file: " << count << endl; // Outputting number of spaces
    
    return 0;
}
