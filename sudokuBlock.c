#include <stdio.h>
#include <ctype.h>
#include "headers.h"

void sudokuBlock(int **displayValues, char canChangeVal[][9]){
  printf("    1 2 3   4 5 6   7 8 9 \n  |-----------------------|\n");
  
  for(int i = 0; i < 9; i++){
    printf("%d |", i+1);
    
    for(int j = 0; j < 9; j++){
      
      if(displayValues[i][j] == 0){
      	printf("\033[0;37m #");//print white
      }else{
      	if(canChangeVal[i][j] == 'y'){
      		printf("\033[0;33m %i", displayValues[i][j]);//print in yellow
      	}else{
      		printf("\033[0;36m %i", displayValues[i][j]);//print in cyan
      	}
      }
      
      if(j == 2 || j == 5){
        printf("\033[0;37m |");//print white
      }
    }
    
    printf("\033[0;37m |\n");//print white
    
    if(i == 2 || i == 5){
      printf("\033[0;37m  |-----------------------|\n");//print white
    }
  }
  
  printf("\033[0;37m  |-----------------------|\n");//print white
}


