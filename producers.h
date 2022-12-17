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
  char passwordLine[256];
  char md5[33]; // 32 characters + null terminator


//check without prefixes
    while (fgets(line, sizeof(line), dictionaryFile))
  {
    
	bytes2md5(line, strlen(line), md5);
	FILE *passwordFile = fopen(passwordsFileName, "r");


    while(fgets(passwordLine, sizeof(passwordLine), passwordFile)){
		
		struct User user;
		separateStringBySpace(passwordLine, &user);

		if(strcmp(md5, user.hashedPassword) == 0){
			printf("Password for %s is %s\n", user.mail, line);
		}
}
	fclose(passwordFile);

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
    removeSpaces(str);
    
    strcat(str, "\n");
    // printf("%s", str);
	bytes2md5(str, strlen(str), md5);

	FILE *passwordFile = fopen(passwordsFileName, "r");

    while(fgets(passwordLine, sizeof(passwordLine), passwordFile)){
		
		struct User user;
		separateStringBySpace(passwordLine, &user);
       
		if(compareStrings(md5, user.hashedPassword)){
			printf("Password for %s is %s\n", user.mail, str);
      }
    }
    fclose(passwordFile);
    free(str);
    //postfix
    str = malloc(1);
    sprintf(str, "%d", counter);
    strcat(line, str);
    
    removeSpaces(line);
    strcat(line, "\n");

	bytes2md5(line, strlen(line), md5);


	passwordFile = fopen(passwordsFileName, "r");

    while(fgets(passwordLine, sizeof(passwordLine), passwordFile)){
		
		struct User user;
		separateStringBySpace(passwordLine, &user);
       
		if(compareStrings(md5, user.hashedPassword)){
			printf("Password for %s is %s\n", user.mail, line);
      }
    }
	free(str);
  fclose(passwordFile);
 
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