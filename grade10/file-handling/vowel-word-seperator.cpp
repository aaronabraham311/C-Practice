// Including all pertinent libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    ifstream inputFile ("text1.txt"); // Creating ifstream and ofstream objects and linking to file
    ofstream outputFile ("text2.txt");
    
    char temp[20]; // Establishing temporary word array to store words
    
    while (!inputFile.eof()) // Running loop until end of file
    {
        inputFile >> temp; // Putting word into array
        
        if ((temp[0] != 'A') || (temp[0] != 'E') || (temp[0] != 'I') || (temp[0] != 'O') || (temp[0] != 'U')) // Outputting word if it does not begin with capital vowel
        {
            outputFile << temp << " ";
        }
    }
    
    // Closing files
    inputFile.close();
    outputFile.close();
    
    return 0;
}
