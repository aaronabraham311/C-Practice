#include <iostream>

using namespace std;

// Declaring enum: puts integer values for closed and open
enum doors
{
    closed = 0, open = 1
};

// Prototypes for functions
void closeDoors (enum doors array[]);
void openClose (enum doors array[]);
void display (enum doors array[]);

int main()
{
    enum doors mailboxes[150]; // Declaring enum array for 150 mailboxes
    
    // Calling 3 functions to close, open, and display mailboxes
    closeDoors (mailboxes);
    openClose (mailboxes);
    display (mailboxes);
    
    return 0;
}

// Function for closing all mailboxes
void closeDoors (enum doors array[])
{
    for (int counter = 0; counter < 150; counter ++) // Closes all mailboxes through a loop
    {
        array[counter] = closed;
    }
    
    return;
}

// Opens and closes mailboxes according to rule
void openClose (enum doors array[])
{
    for (int counter = 2; counter <= 150; counter ++)
    {
        for (int arrayCounter = 0; arrayCounter < 150; arrayCounter ++)
        {
            if ((arrayCounter + 1) % counter == 0) // If mailbox number is nth value (2nd, 3rd, 4th,...), will close or open it
            {
                if (array[arrayCounter] == closed) // Opens mailbox if closed
                {
                    array[arrayCounter] = open;
                }
                else // Closes mailbox if open
                {
                    array[arrayCounter] = closed;
                }
            }
        }
    }
    
    return;
}

// Displays closed mailboxes
void display (enum doors array[])
{
    cout << "Closed mailboxes are: " << endl;
    
    for (int counter = 0; counter < 150; counter ++)
    {
        if (array[counter] == closed) // Outputs mailbox number if it is closed
        {
            cout << "Mailbox " << counter + 1 << endl;
        }
    }
    
    return;
}
