#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "headers.h"

int main(){
  char gameFilename[50];//string input file
  //max amount of characters in file:
  //9 lines; 9 single-digit numbers per line + space or newline + possibility of asterisk
  //9 * (9*3) = 3^5 = 243
  char gamePuzzleFileContent[243];
  int indexOfLastCharInFile;
  int **sudVals;
  char isSetVal[9][9];
  userInput rcv = {0,0,0,0};
  int inputIs;
  
  //Allocate memory to sudoku values (sudVals) array
  sudVals = calloc(9, sizeof(int *));
  for (int i = 0; i < 9; i++) {
    sudVals[i] = calloc(9, sizeof(int));
  }

  //print rules and get user input for name of game file
  printf("- - - - - - - - - - - SUDOKU GAME - - - - - - - - - - -\n\nRULES: Fill the 9x9 square such that each row, column,\n       or block contains all of the numbers 1-9\n\nEnter game filename to load: ");
  scanf("%s",gameFilename);

  //open and read file into array gamePuzzleFileContent
  //the number that gets returned is the index of the last character in the array
  indexOfLastCharInFile = storeTxtFile(gameFilename, gamePuzzleFileContent);
  //test if storing file in gamePuzzleFileContent worked properly - DELETE LATER
  /*printf("\n\n");
  for(int i = 0; i < indexOfLastCharInFile; i++){
    printf("%c ", gamePuzzleFileContent[i]);
  }
  printf("\n\n");*/
  
  //store the ints in an array that will be used to display the game board
  //the number that is returned is the amount of unsolved spaces
  rcv.emptySpotsLeft = fillInitialSud(gamePuzzleFileContent, indexOfLastCharInFile, sudVals, 0, isSetVal);

  //print loading statement and load game
  printf("\nLoading game file %s\nCurrent puzzle has %i unsolved items\n\n",gameFilename,rcv.emptySpotsLeft);
  sudokuBlock(sudVals, isSetVal);
  
  //recieve user input to play game
  while(rcv.emptySpotsLeft != 0){
  	rcv = inputVal(rcv.emptySpotsLeft);
  	
		//break out of the while if user manually exits
		if(rcv.row == -1){
			//exit game by user command
			printf("\nExiting game immediately by user command \nOne Solution Board for this puzzle: \n\n");
			fillInitialSud(gamePuzzleFileContent, indexOfLastCharInFile, sudVals, 1, isSetVal);
			sudokuBlock(sudVals, isSetVal);
			break;
		}
		
  	//test if setting rcv works properly:
  	//printf("row: %i, col: %i, val: %i, unsolved spaces: %i\n", rcv.row, rcv.col, rcv.val, rcv.emptySpotsLeft);
  	inputIs = testSudVal(rcv, sudVals, isSetVal);
  	if(inputIs == 1){
  		rcv.emptySpotsLeft--;
			printf("\nCurrent puzzle has %i unsolved items\n\n", rcv.emptySpotsLeft);
  		sudokuBlock(sudVals, isSetVal);
  	}else if(inputIs == 2){
  		rcv.emptySpotsLeft++;
			printf("\033[0;32mThis spot is now empty.\n\033[0;37mCurrent puzzle has %i unsolved items\n\n", rcv.emptySpotsLeft);
  		sudokuBlock(sudVals, isSetVal);
  	}else if(inputIs == 3){
			printf("\033[0;32mThis spot has been replaced with the new value.\n\033[0;37mCurrent puzzle has %i unsolved items\n\n", rcv.emptySpotsLeft);
  		sudokuBlock(sudVals, isSetVal);
  	}
  }
  
  if(rcv.emptySpotsLeft == 0){
		//exit game bc no empty spots left
		printf("\nGame Complete!\nThis solution board is valid, you win!\n\n");
  }
  
  //Make sure to free the array!!
  for (int i = 0; i < 9; i++) {
  	free(sudVals[i]);
  }
  free(sudVals);

  return 0;
}
