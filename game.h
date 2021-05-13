#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

void gameInit();// fill the two-dimensional array 4 * 4 with numbers from 1 to 15 in a chaotic manner
void frame(COORD left,COORD right);// we build a frame with the help of special symbols
void cursorOff();// make the cursor invisible
void printField(COORD pos);// display the game board with a combination of numbers and an empty cell
int notEndYet();//placement of elements in which the combination is not advantageous
int gameMove();// we rearrange the elements of the field using the keys

int** field;
int emptyCell_x, emptyCell_y;
HANDLE hout;
