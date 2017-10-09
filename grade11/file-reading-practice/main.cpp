// Including libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

void outputLine (int account, const string& name, double balance);

int main()
{
    /*
    // Example 1:
    ofstream outClientFile ("clients.txt", ios::out);

    // Exit program if unable to create file
    if (!outClientFile)
    {
        cerr << "File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Enter the account, name and balance. \n" << "Enter end-of-file to end input. \n?";

    int account; // account number
    string name; // owner name
    double balance; // balance of account

    while (cin >> account >> name >> balance)
    {
        outClientFile << account << "   " << name << "  " << balance << endl;
    }

    outClientFile.close();
    */

    // Example 2
    ifstream inClientFile ("clients.txt", ios :: in);

    if (!inClientFile)
    {
        cerr << "File could not be opened. " << endl;
        exit(EXIT_FAILURE);
    }

    cout << left << setw(10) << "Account" << setw(13) << "Name" << "Balance\n" << fixed << showpoint;

    int account;
    string name;
    double balance;

    while (inClientFile >> account >> name >> balance)
    {
        outputLine(account, name, balance);
    }

    inClientFile.close();

    return 0;
}

void outputLine (int account, const string& name, double balance)
{
    cout << left << setw(10) << account << setw(13) << name << setw(7) << setprecision(2) << right << balance << endl;
    return;
}
