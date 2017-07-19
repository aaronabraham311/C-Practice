//add one
int s (int x)
{
    return x+1;
}

// Uses add one function to add multiple times
int add (int firstNumber, int secondNumber)
{
    int sum = firstNumber;
    
    // As long as counter is not equal to the second number, 1 will be added every time to the first number
    for (int counter = 0; counter != secondNumber; counter = s(counter))
    {
        sum = s(sum);
    }
    
    return sum;
}

// Subtracts one from a number
int subtractOne (int number)
{
    int sum;
    
    // Adds 1 to sum everytime, and breaks if the goal number can be achieved by adding 1 to it, effectively subtracting 1 from original number
    for (sum = 0; sum != number; sum = s(sum))
    {
        if (s(sum) == number)
            break;
    }
    
    return sum;
}

// Finds if first number is less than second number
bool lessThan (int firstNumber, int secondNumber)
{
    // Making infinite loop, which subtracts 1 from both numbers. If the first number reaches 0 first, then it must be less than the second number, therfore true. If it is the opposite, then it must be greater than the second number, therefore false. If it is equal, then this function returns false
    while (true)
    {
        
        if (firstNumber == 0 && secondNumber != 0)
            return true;
        else if (secondNumber == 0 && firstNumber != 0)
            return false;
        else if (firstNumber == secondNumber)
            return false;
        else
        {
            firstNumber = subtractOne (firstNumber);
            secondNumber = subtractOne (secondNumber);
        }
    }
    
    return false;
}

// Subtracts one number from another number
int subtract (int firstNumber, int secondNumber)
{
    int sum = 0;
    int greaterNumber;
    int smallerNumber;
    
    // Finds biggest and smallest number to find a positive difference
    if (lessThan(firstNumber, secondNumber) == true)
    {
        greaterNumber = secondNumber;
        smallerNumber = firstNumber;
    }
    else
    {
        greaterNumber = firstNumber;
        smallerNumber = secondNumber;
    }
    
    // Subtracts one from counter while adding 1 to the sum, finding the difference between two numbers
    for (int counter = greaterNumber; counter != smallerNumber; counter = subtractOne (counter))
    {
        sum = s(sum);
    }
    
    return sum;
}

// Finds if first number is greater than or equal number to second number
bool greaterThanOrEqual (int firstNumber, int secondNumber)
{
    // If the numbers do not fulfill the lessThan function, then the first number must be greater than or equal to the second number
    if (lessThan(firstNumber, secondNumber) != true)
        return true;
    
    return false;
}

// Finds if the first number is greater than the second number
bool greaterThan (int firstNumber, int secondNumber)
{
   // Finds if number is greater than or equal to each other
    if (greaterThanOrEqual(firstNumber, secondNumber) == true)
   {
       // If the numbers are equal, function return false. If not, the first number must be greater than the second number
       if (firstNumber == secondNumber)
       {
           return false;
       }
       else
       {
           return true;
       }
   }
    
    return false;
}

// Multiplies two numbers
int multiply (int firstNumber, int secondNumber)
{
    int sum = 0;
    
    // Repeatedly adds firstNumber to the sum while the counter is less than secondNumber. This basically adds the firstNumber to sum (secondNumber) times.
    for (int counter = 0; lessThan (counter, secondNumber) == true; counter = s(counter))
    {
        sum = add(sum, firstNumber);
    }
    
    return sum;
}

// Divides greater number by smaller number
int divide (int firstNumber, int secondNumber)
{
    int greaterNumber, smallerNumber;
    int counter = 0;
    
    // Finds greater number and smaller number. Also, if the two numbers are equal, function returns 1.
    if (greaterThan (firstNumber, secondNumber) == true)
    {
        greaterNumber = firstNumber;
        smallerNumber = secondNumber;
    }
    else if (greaterThan (secondNumber, firstNumber) == true)
    {
        greaterNumber = secondNumber;
        smallerNumber = firstNumber;
    }
    else if (firstNumber == secondNumber)
    {
        return 1;
    }
    
    int sum = greaterNumber;
    
    // Every time loop runs, the sum (the greater number) is subtracted by smallerNumber, until the sum becomes less than the smaller number
    while (true)
    {
        counter = s(counter);
        sum = subtract (sum, smallerNumber);
        
        if (lessThan (sum, smallerNumber) == true)
            break;
    }
    
    return counter;
}

// Finds remainder of division of firstNumber and secondNumber
int modulo (int firstNumber, int secondNumber)
{
    int greaterNumber, smallerNumber;
    int counter = 0;
    
    //Finds greater and smaller numbers
    if (greaterThan (firstNumber, secondNumber) == true)
    {
        greaterNumber = firstNumber;
        smallerNumber = secondNumber;
    }
    else if (greaterThan (secondNumber, firstNumber) == true)
    {
        greaterNumber = secondNumber;
        smallerNumber = firstNumber;
    }
    else if (firstNumber == secondNumber)
    {
        return 0;
    }
    
    // Establishes reference, and the product of the quotient of division and smallerNumber
    int check = greaterNumber;
    int quotient = divide (greaterNumber, smallerNumber);
    int sum = multiply (quotient, smallerNumber);
    
    // Every time loop runs, the sum is compared to the check, and if they are equal, loop breaks. Otherwise, 1 is added the sum and the counter
    while (true)
    {
        if (sum == check)
            break;
        else
        {
            sum = s(sum);
            counter = s(counter);
        }
    }
    
    return counter;
}
