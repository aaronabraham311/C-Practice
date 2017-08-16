//Including all libraries
#include <iostream>
#include <fstream>

using namespace std;

// Declaring classes for winter and summer decisions
class winterChoices;

// Summer decision class
class summerChoices
{
private:
     double totalCost = 0; // Initializing total cost for summer repairs
public:
    void crack(); // Function that gets user's choice for crack repair
    summerChoices() // Constructor that resets cost to 0
    {
        totalCost = 0;
    }
    friend void totalCost (bool previous, summerChoices summerRepair, winterChoices winterRepair); // Declaring a friend function to calculate final costs
    friend void reset(summerChoices summerRepair, winterChoices winterRepair); // Resets class
};

// Winter decision class
class winterChoices
{
private:
    double totalCost = 0; // Initializing total cost for winter repairs
public:
    void wash(); // Function that gets user's choice for washing
    winterChoices() // Constructor that resets cost to 0
    {
        totalCost = 0;
    }
    friend void totalCost (bool previous, summerChoices summerRepair, winterChoices winterRepair);// Declaring a friend function to calculate final costs
    friend void reset(summerChoices summerRepair, winterChoices winterRepair);
};

bool checkRecord(char id[]); // Functions checks records to see if user is a previous user or not
void reset(summerChoices summerRepair, winterChoices winterRepair); // Resets totalCost variable of both classes

int main()
{
    // Declaring all variables and objects
    char season;
    char userID[2];
    char redoDecision;
    bool prevCustomer;
    
    do
    {
        winterChoices winterRepair;
        summerChoices summerRepair;
        
        // Welcomes user and introduces user to ID checking system
        cout << "Hello, user! Welcome to the Acme Car Maintenance company. In this user interface, you will find the total cost of your car maintenance." << endl << endl;
        
        cout << "You will now enter your ID number. If you are a previous user, please input your previously used ID. If not, please make a new 2 - digit ID. " << endl;
        
        // Gets 2 digit ID number
        for (int i = 0; i < 2; i ++)
        {
            cout << "Please enter the " << i + 1 << " number of the ID: ";
            cin >> userID[i];
        }
        
        // Will return true if user is a previous user, and false if user is new
        prevCustomer = checkRecord(userID); // Compare each ID number with each index. Put a limit on index to 50
        
        // Letting user know if they are a previous customer or not
        if (prevCustomer == true)
        {
            cout << "******************" << endl;
            cout << "From our records, it seems that you are a previous customer. You are eligible for a 20% discount of the total cost of your repairs! Enjoy!" << endl;
        }
        else
        {
            cout << "******************" << endl;
            cout << "It seems that you are a new user. Unfortunately, you are not eligible for a 20% discount of the total cost of your repairs today. However, you are now entered into our user database and will be eligible for this discount the next time you return." << endl;
        }
        
        // Getting season and sanitizing all data
        do
        {
            cout << "******************" << endl;
            cout << "Please enter which season (w for winter, s for summer): ";
            cin >> season;
        } while (season != 'w' && season != 's');
        
        // Calling respective objects and getting user's decision
        if (season == 'w')
        {
            
            winterRepair.wash();
        }
        else
        {
            summerRepair.crack();
        }
        
        // Outputting cost to user
        cout << "******************" << endl;
        cout << "The cost breakdown of your repairs or washes is: " << endl;
        totalCost(prevCustomer, summerRepair, winterRepair);

        // Asks employer if they would like to continue with ID entering and sanitizes input
        do
        {
            cout << "Would you like to continue to enter ID's (y/n): ";
            cin >> redoDecision;
        } while (redoDecision != 'y' && redoDecision != 'n');
        
    } while (redoDecision == 'y');
    
    cout << "Have a good day." << endl;
    
    return 0;
}

bool checkRecord(char id[])
{
    // Declaring all objects and variables
    ifstream record ("user_record.txt"); // Opens file to get ID from record
    bool idCheck = false;
    char tempID[2];
    
    // Loop gets each line of text in file and checks each array index if they are the same and changes the bool value if the file line is identical to the user's id
    while (!record.eof())
    {
        record >> tempID;
        
        if (id[0] == tempID[0] && id[1] == tempID[1])
        {
            idCheck = true;
            break;
        }
    }
    // If the user's ID is not found in the file, the following code will run
    if (idCheck == false)
    {
        fstream outputRecord ("user_record.txt", ios :: app | ios :: out); // Will open same file for writing and moves file pointer to end
        
        // Sets file up and also outputs the user's ID into the file
        outputRecord << endl;
        
        for (int i = 0; i < 2; i ++)
        {
            outputRecord << id[i];
        }
        
        // Closing file
        outputRecord.close();
    }
    
    // Closing file
    record.close();
    
    // Returns true if user's ID is found in file, or false if the ID is new
    return idCheck;
}

void summerChoices:: crack()
{
    // Declaring all relevant variables
    char userDecision;
    char confirm = 'n';
    
    // If user does not agree to the price or if it is their first time
    while (confirm == 'n')
    {
        cout << "******************" << endl;
        
        // Getting user's decision on type of crack to repair and sanitizing data
        do
        {
            cout << "What kind of crack would you like to repair? If you would like to repair a small crack, please input 's'. If you would like to repair a big crack, please input'b': ";
            cin >> userDecision;
        } while (userDecision != 's' && userDecision != 'b');
        
        // If the user opts for a small crack repair
        if (userDecision == 's')
        {
            // Outputs the cost and gets user's confirmation
            do
            {
                cout << "******************" << endl;
                cout << "You have chosen to repair a small crack, which costs 100 CAD. Please confirm by inputting 'y' for confirmation, or 'n' if you would like to redo your decision: ";
                cin >> confirm;
            } while (confirm != 'n' && confirm != 'y');
            
            // If the user confirms the cost, the function will add the cost into the class
            if (confirm == 'y')
            {
                totalCost += 100;
            }
            
        }
        else // If the user opts for a big crack repair
        {
            // Outputs the cost and gets user's confirmation
            do
            {
                cout << "******************" << endl;
                cout << "You have chosen to repair a big crack, which costs 150 CAD. Please confirm by inputting 'y' for confirmation, or 'n' if you would like to redo your decision: ";
                cin >> confirm;
            } while (confirm != 'n' && confirm != 'y');
            
            // If the user confirms the cost, the function will add the cost into the class
            if (confirm == 'y')
            {
                totalCost += 150;
            }
        }
    }
    
    return;
}

void totalCost (bool previous, summerChoices summerRepair, winterChoices winterRepair)
{
    double total = summerRepair.totalCost + winterRepair.totalCost; // Gets the subtotal by adding the totals of winter and summer repairs
    
    cout << endl;
    
    // Outputs the cost with a discount if user has came to store before
    if (previous == true)
    {
        cout << "Subtotal: " << total  << " CAD" << endl;
        cout << "Eligible discount: " << total * 0.2 << " CAD" << endl;
        total *= 0.8;
        cout << "Total: " << total << " CAD" << endl;
    }
    else // Outputs the cost without a discount if the user is new
    {
        cout << "Subtotal: " << total << " CAD" << endl;
        cout << "Eligible discount: " << 0 << " CAD" << endl;
        cout << "Total: " << total << " CAD" << endl;
    }
    
    return;
}

void winterChoices:: wash()
{
    // Declaring all relevant variables
    char userDecision;
    char confirm = 'n';
    
    // If user does not agree to the price or if it is their first time
    while (confirm == 'n')
    {
        cout << "******************" << endl;
        
        // Getting user's decision on type of wash and sanitizing data
        do
        {
            cout << "What kind of wash would you like? If you would like a inner wash, please input 'i'. If you would like a inner and outer wash, please input'b': ";
            cin >> userDecision;
        } while (userDecision != 'i' && userDecision != 'b');
        
        // If the user opts for an inner wash
        if (userDecision == 'i')
        {
            do
            {
                cout << "******************" << endl;
                cout << "You have chosen an inner wash for your car, which costs 80 CAD. Please confirm by inputting 'y' for confirmation, or 'n' if you would like to redo your decision: ";
                cin >> confirm;
            } while (confirm != 'n' && confirm != 'y');
            
            // If the user confirms the cost, the function will add the cost into the class
            if (confirm == 'y')
            {
                totalCost += 80;
            }
            
        }
        else // If the user opts for an inner and outer wash
        {
            // Outputs the cost and gets user's confirmation
            do
            {
                cout << "******************" << endl;
                cout << "You have chosen an inner and outer wash for your car, which costs 200 CAD. Please confirm by inputting 'y' for confirmation, or 'n' if you would like to redo your decision: ";
                cin >> confirm;
            } while (confirm != 'n' && confirm != 'y');
            
            // If the user confirms the cost, the function will add the cost into the class
            if (confirm == 'y')
            {
                totalCost += 200;
            }
        }
    }
    
    return;
}
