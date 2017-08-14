// Including all libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

// Making structure with random values
struct fileStructure
{
    // Defining random structure members
    int randomNumber = 12;
    string randomString = "Hello";
    char  randomCharacter = '*';
};

// Declaring function
void fread();

int main()
{
    fwrite(); // Calling function to write into file
    ifstream readFile ("someFile.txt"); // Creating ifstream object that links with someFile.txt
    char numberText;

    while (!readFile.eof()) // Reads through all characters in the file until end
    {
        readFile.get(numberText); // Getting character and putting it into variable
        
        cout << numberText; // Outputting character
    }
    
    readFile.close(); // Closing file */
     
    return 0;
}

void fwrite()
{
    ofstream file ("someFile.txt"); // Creating ofstream object linked with someFile.txt
    
    fileStructure f [10]; // Making array of structures
    
    for (int i = 0; i < 10; i ++) // Writing array into file
    {
        file << f[i].randomNumber << " " << f[i].randomCharacter << " " << f[i].randomString << endl;
    }
    
    file.close(); // Closing file;
    
    return;
}
