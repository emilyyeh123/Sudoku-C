#include <stdio.h>
#include <ctype.h>
#include "headers.h"

//open and store file contents into arr
//array contents that get stored in this function will be passed by reference and values will be remembered in main
//returns the number where the function stopped so the program knows the index of the last new value in the array
int storeTxtFile(char fileName[], char storeFileContents[]){
  FILE *fileptr;
  int i = 0;
  
  fileptr = fopen(fileName,"r");
  while(!feof(fileptr)){
    storeFileContents[i] = (char)fgetc(fileptr);
    i++;
  }
  fclose(fileptr);

  return i;
}
