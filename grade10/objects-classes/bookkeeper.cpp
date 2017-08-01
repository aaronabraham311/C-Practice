// Declaring libraries
#include <iostream>
#include <string>

using namespace std;

class BOOK
{
private:
    int number; // Number of books to be purchased
    string title; // Title (will sanitize later to make sure charachters is less than 21 character
    float price; // Price of one book
    float TOTAL_COST (); // Calculates price of all books purchased
public:
    void INPUT(); // Function to input all information
    void PURCHASE(); // Function to ask for purchase of books and displaying cost
};

int main()
{
    BOOK userBook; // Declaring object
    
    cout << "Hello! Welcome to the bookkeeper program." << endl; // Welcoming user
    
    userBook.INPUT(); // Calling input function
    userBook.PURCHASE(); // Calling purchase function
    
    return 0;
}

void BOOK:: INPUT()
{
    // Getting book number and sanitizing to make sure it is not negative
    do
    {
        cout << "Please enter the book number: ";
        cin >> number;
    } while (number < 0);
    
    // Getting title and sanitizing to make sure it is less than 21 characters
    do
    {
        cout << "Please enter the book title: ";
        cin.ignore();
        getline (cin, title);
    } while (title.length() > 21);
    
    // Gets price of one book and making sure it is not negative
    do
    {
        cout << "Please enter the price of one book: ";
        cin >> price;
    } while (price < 0);
    
    return;
}

void BOOK:: PURCHASE()
{
    // Gets number of books to be purchased, and sanitizing to make sure it is not negative
    do
    {
        cout << "Please enter the number of books wished to be purchased: ";
        cin >> number;
    } while (number < 0);
    
    // Displaying total cost by calling function
    cout << "The total cost of the purchase is: $" << TOTAL_COST() << endl;
    
    return;
}

float BOOK:: TOTAL_COST ()
{
    return price * number; // Multiplies price and number to find total cost
}
