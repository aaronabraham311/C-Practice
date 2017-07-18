#include <iostream>
#include <string>

using namespace std;

int main()
{
    int userNum;
    int counter;
    string star = "";
    
    cout << "Please input a positive number: ";
    cin >> userNum;
    
    counter = userNum;
    
    while (counter > 0)
    {
        star += "*";
        counter --;
    }
    
    cout << star << endl;
    
    counter = userNum;
    
    while (counter > 1)
    {
        star.erase(star.length()-1,1);
        cout << star << endl;
        counter --;
    }
    
    counter = userNum;
    
    while (counter > 0)
    {
        star += "*";
        cout << star << endl;
        counter --;
    }
    
    return 0;
}
