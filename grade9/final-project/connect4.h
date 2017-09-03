#ifndef connect4_h
#define connect4_h

// Prototypes of all functions
bool draw(char array[6][7]);
void spaces(char array[6][7]);
void printArray(char Array[6][7]);
int updateboard(char Array[6][7], int column);
bool checkColumn (char array[6][7], int userRow, int userColumn);
bool checkRow (char array[6][7], int userRow, int userColumn);
bool checkDiagonal (char array[6][7], int userRow, int userColumn);
void popoutfunc(int column, char Array[6][7]);


#endif /* connect4_h */
