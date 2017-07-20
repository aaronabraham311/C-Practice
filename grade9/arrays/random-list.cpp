// Declaring libraries and prototypes
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int randomNumber ();
float randomDecimal ();

int main()
{
    // Seeding random number with time
    srand (time(NULL));
    
    // Making array with 5 elements
    float randomArray[5];
    
    // Making loop that inputs 5 random integers into the array in the loop
    cout << "Inputting 5 random integers in the array: " << endl;
    
    for (int index = 0; index < 5; index ++)
    {
        randomArray[index] = randomNumber();
        cout << randomArray[index] << endl;
    }
    
    // Making loop that inputs random decials into the array in the loop
    cout << "Inputting 5 random decimals in the array: " << endl;
    
    for (int index = 0; index < 5; index ++)
    {
        randomArray [index] = randomDecimal();
        cout << randomArray[index] << endl;
    }
    
    return 0;
}

int randomNumber()
{
    // Making random number that is based off the remainder of division by 11
    int randomNum = rand() % 11;
    return randomNum;
}

float randomDecimal()
{
    // Making random decimal by dividing random number by the maximum number
    float randomDec = (float (rand()) / RAND_MAX);
    return randomDec;
}
