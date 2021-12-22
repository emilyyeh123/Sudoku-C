#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "headers.h"

userInput inputVal(int emptySpaceCount){
	char input[5];
	userInput rcVal = {0,0,0,emptySpaceCount};
	char temp;
	//rcVal.emptySpotsLeft = emptySpaceCount;
	
	printf("\nEnter row,col,value to solve a square, or -1 to exit;\nTo empty a space you previously filled, enter row,col,0: ");
	scanf("%s", input);
	
	if(input[0] == '-'){
		rcVal.row = -1;
		rcVal.col = -1;
		rcVal.val = -1;
	}else{
		//print statements used to test if setting variables worked properly
		temp = input[0];
		//printf("temp = %c, atoi(&temp) = %i \n", temp, atoi(&temp));
		rcVal.row = atoi(&temp);
		temp = input[2];
		//printf("temp = %c, atoi(&temp) = %i \n", temp, atoi(&temp));
		rcVal.col = atoi(&temp);
		temp = input[4];
		//printf("temp = %c, atoi(&temp) = %i \n", temp, atoi(&temp));
		rcVal.val = atoi(&temp);
	}
	
	return rcVal;
}
