#include <openssl/evp.h>
#include <string.h>
#include <stdio.h>
#include "utils.h"

//małe litery
void oneWord0(char *dictionaryFileName, char *passwordsFileName){
 FILE *dictionaryFile = fopen(dictionaryFileName, "r");
 
  if (dictionaryFile == NULL)
  {
    printf("Failed to open the file: %s\n", dictionaryFileName);
    return;
  }
  // Read the file line by line
  char *line = malloc(256);

//check without prefixes
    while (fgets(line, sizeof(line), dictionaryFile))
  {
    
	checkPassword(line, passwordsFileName);
	}


//check with numbers
  int counter = 0;
    while(1){
    FILE *dictionaryFile = fopen(dictionaryFileName, "r");
  while (fgets(line, sizeof(line), dictionaryFile))
  {
    char *newLine = malloc(256);
    char *str = malloc(1);
    newLine = line;
    sprintf(str, "%d", counter);
     //prefix
  
   strcat( str, line);
	checkPassword(str, passwordsFileName);
free(str);


    //postfix
    str = malloc(1);
    sprintf(str, "%d", counter);
    strcat(line, str);
    
    checkPassword(line, passwordsFileName);
  free(str);
	}
     counter++;
     
       
    }

  }

  // Close the file
  fclose(dictionaryFile);
  
//pierwsza wielka litera
void oneWord1(){}
//wszystkie wielkie
void oneWord2(){}
void twoWords(){}