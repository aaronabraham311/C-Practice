#include <iostream>
using namespace std;

int main()
{
    int num; // Declaring variables
    
    cout<<"Please enter a number: "; // Getting input from number
    cin>>num;
    
    cout<<"The thousands digit is: "<< (num%10000)/1000<<endl; // Doing operations to find digits
    cout<<"The hundreds digit is: "<<(num%1000)/100<< endl;
    cout<<"The tens digit is: "<< (num%100)/10<< endl;
    cout<<"The ones digit is: "<< num%10<< endl;
    
    return 0;
}
