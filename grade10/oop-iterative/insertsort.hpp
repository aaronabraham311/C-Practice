#ifndef insertsort_hpp
#define insertsort_hpp

// Declaring insert sort class
class insertsort
{
private:
    int size, i, j, temp; // Declaring variables neccessary for insert sort
    int array[]; // Declaring array
public:
    void enteriarray(); // Declaring all neccessary functions
    void sortinsert();
    void displaysortinsert();
};

#endif /* insertsort_hpp */
