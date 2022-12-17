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
    //prefix
    char *prefix = malloc(256);
    char *postfix = malloc(256);
    sprintf(prefix, "%d", counter);
    strcat( prefix, line);
	  checkPassword(prefix, passwordsFileName);
    free(prefix);
    free(postfix);

    //prefix with all less postfixes
    for(int i = 0; i<=counter; i++){
    prefix = malloc(256);
    postfix = malloc(256);
    sprintf(prefix, "%d", counter);
    sprintf(postfix, "%d", i);
    strcat( prefix, line);
    strcat(prefix, postfix);
	  checkPassword(prefix, passwordsFileName);
    free(prefix);
    free(postfix);
    }

    //postfix
    prefix = malloc(256);
    postfix = malloc(256);
    sprintf(postfix, "%d", counter);
    strcat(line, postfix);
    checkPassword(line, passwordsFileName);
    free(postfix);

    //postfix with all less prefixes
    for(int i = 0; i<=counter; i++){
    prefix = malloc(256);
    postfix = malloc(256);
    sprintf(postfix, "%d", counter);
    sprintf(prefix, "%d", i);
    strcat(prefix, line);
	  checkPassword(prefix, passwordsFileName);
    free(prefix);
    free(postfix);
    }
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