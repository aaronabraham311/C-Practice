#include <iostream>

using namespace std;

bool isPrime(int);
int nextPrime(int);
int numDivs(int, int);

int main()
{
    int num, primeFac, exponent;
    int counter = 1;
    
    cout << "Please enter a number: ";
    cin >> num;
    
    // Making loop for prime factorization
    for(primeFac = 2; primeFac < num; primeFac = nextPrime(primeFac), counter++)
    {
        exponent = numDivs(primeFac, num);
        
        if (exponent != 0) // Taking out any prime factors raised to 0
        {
            if (counter == 1) // When counter == 1, there will be no multiplication sign at front but otherwise there is
            {
                cout << primeFac << '^' << exponent;
            }
            else
            {
                cout << " * " << primeFac << '^' << exponent;
            }
        }
    }
    cout << endl;
    
    return 0;
}

bool isPrime(int candidate) // Function finds if certain number is prime or not
{
    bool primeNumber = false;
    
    for(int i = 2; i < candidate; i++)
    {
        if(candidate % i == 0)
        {
            primeNumber = true;
            break;
        }
    }
    
    return primeNumber;
}

int nextPrime(int base) // Gets next prime number after certain number
{
    int next = base;
    bool primeNum;
    
    do
    {
        next ++;
        primeNum = isPrime (next);
    } while (primeNum == true);
    
    return next;
}

int numDivs(int factor, int baseNum) // Establishes if number is divisible and the respective exponent
{
    int exponent = 0;
    while(baseNum % factor == 0)
    {
        exponent++;
        baseNum /= factor;
    }
    return exponent;
}
