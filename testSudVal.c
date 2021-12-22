#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "headers.h"

int testSudVal(userInput rcVal, int **sudokuValues, char canChangeVal[][9]){
	int inputIs = 0;//0 for invalid, 1 for valid, 2 for valid but to empty space, 3 for valid but to replace value
	int rowIsValid = 1;
	int columnIsValid = 1;
	int boxIsValid = 1;
	int r, c;
	rcVal.row--;
	rcVal.col--;
	
	if(canChangeVal[rcVal.row][rcVal.col] == 'n'){
		//test if the spot already has a value assigned to it
		printf("\033[0;31mThat spot cannot be changed. Please try again.\033[0;37m");
	}else if(sudokuValues[rcVal.row][rcVal.col] == rcVal.val){
		//if the val at that spot already equals new input value, print statement
		printf("\033[0;31mThat spot is already set to that value. Please try again.\033[0;37m\n");
	}else if(rcVal.val == 0){
		//if the new val is 0, empty the spot
		inputIs = 2;
		sudokuValues[rcVal.row][rcVal.col] = rcVal.val;
	}else{
		//traverse rows & columns - test if any are invalid
		for(int i = 0; i < 9; i++){
			if(sudokuValues[rcVal.row][i] == rcVal.val){
				//printf("rowIsValid = false\n");
				rowIsValid = 0;
				break;
			}
			if(sudokuValues[i][rcVal.col] == rcVal.val){
				//printf("columnIsValid = false\n");
				columnIsValid = 0;
				break;
			}
		}
		
		//traverse box if rowIsValid AND columnIsValid are both true
		if(rowIsValid == 1 && columnIsValid == 1){
			if(rcVal.row >= 0 && rcVal.row < 3){
				r = 0;
			}else if(rcVal.row >= 3 && rcVal.row < 6){
				r = 3;
			}else if(rcVal.row >= 6 && rcVal.row < 9){
				r = 6;
			}
			//test if this works
			//printf("r = %i\n", r);
			
			if(rcVal.col >= 0 && rcVal.col < 3){
				c = 0;
			}else if(rcVal.col >= 3 && rcVal.col < 6){
				c = 3;
			}else if(rcVal.col >= 6 && rcVal.col < 9){
				c = 6;
			}
			//test if this works
			//printf("c = %i\n", c);
			
			for(int i = r; i < r+3; i++){
				for(int j = c; j < c+3; j++){
					if(sudokuValues[i][j] == rcVal.val){
						//test if this works
						//printf("boxIsValid = false\n");
						boxIsValid = 0;
						break;
					}
				}
				if(boxIsValid == 0){
					break;
				}
			}
		}
		
		if(sudokuValues[rcVal.row][rcVal.col] == rcVal.val){
			printf("\033[0;31mThat spot already holds that value. Please try a new solution.\n\033[0;37m");
		}else if(rowIsValid == 0){
			//test if the spot is valid within the row
			printf("\033[0;31mThe row already has that number. Remember, \nin Sudoku, no number can be repeated within a \nrow, column, or 3x3 box. Please try again.\n\033[0;37m");
		}else if(columnIsValid == 0){
			//test if the spot is valid within the column
			printf("\033[0;31mThe column already has that number. Remember, \nin Sudoku, no number can be repeated within a \nrow, column, or 3x3 box. Please try again.\n\033[0;37m");
		}else if(boxIsValid == 0){
			//test if the spot is valid within the 3x3 box
			printf("\033[0;31mThe 3x3 box already has that number. Remember, \nin Sudoku, no number can be repeated within a \nrow, column, or 3x3 box. Please try again.\n\033[0;37m");
		}else{
			if(sudokuValues[rcVal.row][rcVal.col] == 0){
				inputIs = 1;
			}else{
				inputIs = 3;
			}
			sudokuValues[rcVal.row][rcVal.col] = rcVal.val;
		}
	}
	
	return inputIs;
}

