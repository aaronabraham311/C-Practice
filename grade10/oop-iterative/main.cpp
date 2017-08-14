// Including libraries and header files
#include <iostream>
#include "bubblesort.hpp"
#include "selectsort.hpp"
#include "insertsort.hpp"
#include "quicksort.hpp"

using namespace std;

int main()
{
    // Declaring varaiables and objects
    bubblesort b;
    insertsort i;
    selectsort s;
    quicksort q;
    char userDecision;
    
    cout << "Hello, welcome to sorting program!" << endl;
    
    // Getting user's choice for which sort they would like to perform, and validating their input
    do
    {
        cout << "Please enter 'b' if you would like to perform a bubble sort, an 'i' if you would like to perform an insert sort, a 'q' if you would you like to perform a quick sort, or a 's' if you would like to perform a select sort: ";
        cin >> userDecision;
    } while ( (userDecision != 'b') && (userDecision!= 's') && (userDecision != 'i') && (userDecision != 'q'));
    
    cout << "******************************************************" << endl;
    
    if (userDecision == 'i') // Entering array, sorting using insert sort, and displaying array
    {
        i.enteriarray();
        i.sortinsert();
        i.displaysortinsert();
    }
    else if (userDecision == 'b') // Entering array, sorting bubble sort, and displaying array
    {
        b.enterbarray();
        b.sortbubble();
        b.displaysortbubble();
    }
    else if (userDecision == 's') // Entering array, sorting select sort, and displaying array
    {
        s.entersarray();
        s.sortselect();
        s.displaysortselect();
    }
    else if (userDecision == 'q') // Entering array, sorting using quick sort, and displaying array
    {
        q.enterqarray();
        q.displaysortquick();
    }
    
    cout << "Thank you! See you again. " << endl;
    
    return 0;
}
