// Including libraries

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

// Declarations
enum class RequestType {
    ZERO_BALANCE = 1, CREDIT_BALANCE, DEBIT_BALANCE, END};
RequestType getRequest();
bool shouldDisplay (RequestType, double);
void outputLine(int, const string&, double);

int main()
{
    // Opening file
    ifstream inClientFile("clients.txt", ios::in);

    // Exiting program if file couldn't be opened
    if (!inClientFile)
    {
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }

   // Get user's request
    RequestType request{getRequest()};

    // Process user's request
    while (request != RequestType::END)
    {
        switch(request) {
            case RequestType::ZERO_BALANCE:
                cout << "\nAccounts with zero balances: \n";
                break;
            case RequestType::CREDIT_BALANCE:
                cout << "\nAccounts with credit balances: \n";
                break;
            case RequestType::DEBIT_BALANCE:
                cout << "\nAccounts with debit balances: \n";
                break;
        }

        int account;
        string name;
        double balance;

        // Reading account, name and balance from file
        inClientFile >> account >> name >> balance;

        // Displaying file contents
        while (!inClientFile.eof()) {
            if (shouldDisplay(request,balance))
            {
                outputLine(account, name, balance);
            }

            inClientFile >> account >> name >> balance;
        }

        inClientFile.clear(); // reset eof for next input
        inClientFile.seekg(0); // reposition to beginning of file
        request = getRequest(); // getting additional request
    }

    cout << "End of run" << endl;

    return 0;
}

// Getting request from user
RequestType getRequest()
{
    cout << "\n Enter request\n"
         << "1 - List accounts with zero balances\n"
         << "2 - List accounts with credit balances\n"
         << "3 - List accounts with debit balances\n"
         << "4 - End run" << fixed << showpoint << endl;
    int type;

    do {
        cout << "\n?";
        cin >> type;
    } while (type < static_cast<int>(RequestType::ZERO_BALANCE) || type > static_cast<int>(RequestType::END)); // Doesn't accept outputs greater than 4 or less than 1

    return static_cast<RequestType>(type);
}

bool shouldDisplay (RequestType type, double balance)
{
    if (type == RequestType::ZERO_BALANCE && balance == 0)
    {
        return true;
    }

    if (type == RequestType::CREDIT_BALANCE && balance < 0)
    {
        return true;
    }

    if (type == RequestType::DEBIT_BALANCE && balance > 0)
    {
        return true;
    }

    return false;
}

void outputLine(int account, const string& name, double balance)
{
    cout << left << setw(10) << account << setw(13) << name
         << setw(7) << setprecision(2) << right << balance << endl;
}
