#ifndef quicksort_hpp
#define quicksort_hpp

// Declaring quick sort class
class quicksort
{
private:
    int size = 10, i = 0, j = 9;
    int temp, left, right, pivot; // Declaring variables neccessary for quick sort
    int array[]; // Declaring array
public:
    void enterqarray(); // Declaring all neccessary functions
    void sortquick(int left, int right);
    void displaysortquick();
};

#endif 
