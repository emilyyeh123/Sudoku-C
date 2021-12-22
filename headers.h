#ifndef HEADERS_H
#define HEADERS_H

typedef struct{
  int row;
  int col;
  int val;
  int emptySpotsLeft;
}userInput;

void sudokuBlock(int **displayValues, char canChangeVal[][9]);
int storeTxtFile(char fileName[], char storeFileContents[]);
int fillInitialSud(char fileChar[], int fileSize, int **sudokuValues, int exit, char canChangeVal[][9]);
userInput inputVal(int emptySpaceCount);
int testSudVal(userInput rcVal, int **sudokuValues, char canChangeVal[][9]);

#endif

