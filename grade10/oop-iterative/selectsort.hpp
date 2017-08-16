#ifndef selectsort_hpp
#define selectsort_hpp

// Declaring class for select sort
class selectsort
{
private:
    int size, i, j, temp; // Declaring variables neccessary for select sort
    int array[]; // Declaring array
public:
    void entersarray(); // Declaring all neccessary functions
    void sortselect();
    void displaysortselect();
};

#endif
