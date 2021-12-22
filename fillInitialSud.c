#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "headers.h"

//return number of unfilled spaces
//canChangeVal tells whether the value at r,c can be changed later
//ensures that no set values ever get changed
int fillInitialSud(char fileChar[], int fileSize, int **sudokuValues, int exit, char canChangeVal[][9]){
	int row = 0;
	int col = 0;
	char temp;
	int count = 0;
	
	for(int i = 0; i < fileSize; i++){
		if(col == 9){
			col = 0;
		}
		if(isdigit(fileChar[i])){
			if(exit == 1){
				temp = fileChar[i];
				sudokuValues[row][col] = atoi(&temp);
			}else{
				sudokuValues[row][col] = 0;
				canChangeVal[row][col] = 'y';
			}
			count++;
			col++;
		} else if (fileChar[i] == '*'){
			i++;
			temp = fileChar[i];
			sudokuValues[row][col] = atoi(&temp);
			canChangeVal[row][col] = 'n';
			//during display of sudokuBlock,
			//if the value = 0, the display will print '#' instead
			col++;
		} else if (fileChar[i] == '\n'){
			row++;
		}
	}
	
	return count;
}
