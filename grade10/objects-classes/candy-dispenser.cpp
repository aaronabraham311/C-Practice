#include <iostream>

using namespace std;

// Making class for cash register
class CashRegister
{
private:
    float cashOnHand; // Variable for amount of cash in register
public:
    CashRegister(); // Constructor to initialize amount of money in register
    float getCurrentBalance (); // Returns amount of money in register
    void acceptAmount(int userMoney, int userChange); // Updates cash in register
};

// Making class for each dispenser
class DispenserType
{
private:
    int numberOfItems; // Variable for number of items
    float cost; // Variable for cost of item
public:
    DispenserType(); // Sets number of items and cost of item
    int getNoOfItems(); // Returns number of items
    float getCost(); // Returns cost of item
    void makeSale (int amount); // Decreases number of items in stock based on items sold
    
};

// Function prototypes to show selection and sell prouducts
void showSelection();
void sellProduct (CashRegister dispenserRegister, DispenserType products[4]);

int main()
{
    CashRegister storeRegister; // Making object for store register
    DispenserType storeProducts [4]; // Making object array for each product
    
    char userChoice;
    
    do // Continues process if user wants to continue (types in y)
    {
        // Shows selection and sells products
        showSelection();
        sellProduct (storeRegister, storeProducts);
        
        // Asks if user wants to continue. Data sanitizes to make sure user only inputs y/n
        do
        {
            cout << "Would you like to continue shopping? (y/n)";
            cin >> userChoice;
        } while (userChoice != 'y' && userChoice != 'n');
        
    } while (userChoice == 'y');
    
    cout << "Thank you for shopping! Have a good day!" << endl; // End message
    
    return 0;
}
// CASH REGISTER FUNCTIONS
// Sets register amount
CashRegister:: CashRegister()
{
    cashOnHand = 500;
}

// Gives amount of money in register
float CashRegister::getCurrentBalance()
{
    return cashOnHand;
}

// Takes in amount given by user, and gives change, and accordingly changes balance
void CashRegister::acceptAmount(int userMoney, int change)
{
    cashOnHand += userMoney;
    cashOnHand -= change;
    return;
}

// DISPENSER FUNCTIONS
// Sets number of items for each product and the cost
DispenserType:: DispenserType()
{
    numberOfItems = 50;
    cost = 0.5;
    return;
}

// Returns number of items
int DispenserType:: getNoOfItems()
{
    return numberOfItems;
}

// Returns cost of item
float DispenserType:: getCost()
{
    return cost;
}

// Decreases amount of items in stock based on amount sold
void DispenserType:: makeSale (int amount)
{
    numberOfItems -= amount;
    return;
}

// Shows selection and number required to select the product
void showSelection()
{
    cout << "------------------------------------------------"<< endl;
    cout << "Hello customer! The following products are on display. Choose the product that you would like by typing in the number displayed next to the item: " << endl;
    cout << "Candies (1)" << endl;
    cout << "Chips (2)" << endl;
    cout << "Gum (3)" << endl;
    cout << "Cookies (4)" << endl;
    return;
}

// Sells products
void sellProduct (CashRegister dispenserRegister, DispenserType products[4])
{
    // Declaring variables
    int userChoice;
    int userAmount;
    float userChange;
    float userCost;
    float userPays;
    
    do
    {
        cout << "Please enter the corresponding number for your desired selection: ";
        cin >> userChoice; // Gets number that user wants
        
        userChoice --; // Making variable valid for the products array
        
        if (products[userChoice].getNoOfItems() == 0) // Asks user to choose different item if item is out of stock
        {
            cout << "There are 0 items of this type. Please choose another item." << endl;
        }
    } while (userChoice > 3 || userChoice < 0 || products[userChoice].getNoOfItems() == 0); // Sanitizing to make sure values are valid
    
    cout << "The cost of this product is: $" << products[userChoice].getCost() << endl; // Tells user cost of item
    
    do
    {
        cout << "Please enter the number of items you would like to buy: ";
        cin >> userAmount; // Gets number of items that user wants to buy
    } while (userAmount <= 0); // Data sanitizing to make sure items is not below or equal to zero
    
    // Asks user to input a different number of items if they ask for too many items (i.e. there isn't enough items in stock)
    while (userAmount > products[userChoice].getNoOfItems())
    {
        cout << "There are only " << products[userChoice].getNoOfItems() << " items in stock. Please choose a different amount of items for this product: ";
        cin >> userAmount;
    }
    
    userCost = products[userChoice].getCost() * userAmount; // Getting cost of purchase
    
    do
    {
        // Asking user to pay amount and getting amount
        cout << "Please pay $" << userCost << " by entering the amount: ";
        cin >> userPays;
        
        userChange = userPays - userCost; // Calculating change
        
        if (userChange > dispenserRegister.getCurrentBalance()) // If they give too much money so that the cash register doesn't have enough money to return as change
        {
            cout << "Please enter a lower amount. The cash register does not have money for change." << endl;
        }
    } while (userPays < userCost || userChange > dispenserRegister.getCurrentBalance()); // Making sure user pays right amount and that amount isn't too much for cash register to give change
    
    cout << "You have recieved $" << userChange << " as change for your purchase." << endl; // Tells user how much they recieved as change
    
    dispenserRegister.acceptAmount(userPays, userChange); // Changing amount of money in register
    products[userChoice].makeSale(userAmount); // Decreases amount of item in stock
    
    // Tells what they bought and how much they bought
    cout << "You have made a successful purchase! You have bought " << userAmount;
    
    if (userChoice == 0)
    {
        cout << " candies." << endl;
    }
    else if (userChoice == 1)
    {
        cout << " chips." << endl;
    }
    else if (userChoice == 2)
    {
        cout << " gum." << endl;
    }
    else
    {
        cout << " cookies.";
    }
    
    return;
}
