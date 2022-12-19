#include <openssl/evp.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>
#include "utils.h"

//małe litery
void *oneWord0(){
 char* line = malloc(256);

//check with numbers
  int counter = 0;
  while(1){
    if(counter == 0){
  for(int j=0;j<dictionaryLength; j++){

    strcpy(line,dictionary[j] );
    checkPassword(line, false);
	}
    }
     
  for (int j = 0; j< dictionaryLength; j++)
  {

    strcpy(line,dictionary[j] );
    //prefix
    char *prefix = malloc(256);
    char *postfix = malloc(256);
    sprintf(prefix, "%d", counter);
    strcat( prefix, line);
	  checkPassword(prefix, false);
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
	  checkPassword(prefix, false);
    free(prefix);
    free(postfix);
    }

    //postfix
    prefix = malloc(256);
    postfix = malloc(256);
    sprintf(postfix, "%d", counter);
    strcat(line, postfix);
    checkPassword(line, false);
    free(postfix);

    //postfix with all less prefixes
    for(int i = 0; i<=counter; i++){

    prefix = malloc(256);
    postfix = malloc(256);
    sprintf(postfix, "%d", counter);
    sprintf(prefix, "%d", i);
    strcat(prefix, line);
    strcat(prefix, postfix);
	  checkPassword(prefix, false);
    free(prefix);
    free(postfix);
    }
//  pthread_mutex_unlock(&mutex);
	}

  counter++;
  }
  return NULL;
}
void *oneWord1(){
  char* line = malloc(256);
//check without prefixes


//check with numbers
  int counter = 0;
  while(1){

    if(counter == 0){
      for(int i=0;i<dictionaryLength; i++){

  strcpy(line,dictionary[i] );
    line[0] = toupper(line[0]);
    checkPassword(line, false);
	}
    }
  for (int j = 0; j< dictionaryLength; j++)
  {

    strcpy(line,dictionary[j] );
    line[0] = toupper(line[0]);
    //prefix
    char *prefix = malloc(256);
    char *postfix = malloc(256);
    sprintf(prefix, "%d", counter);
    strcat( prefix, line);
	  checkPassword(prefix, false);
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
	  checkPassword(prefix, false);
    free(prefix);
    free(postfix);
    }

    //postfix
    prefix = malloc(256);
    postfix = malloc(256);
    sprintf(postfix, "%d", counter);
    strcat(line, postfix);
    checkPassword(line, false);
    free(postfix);

    //postfix with all less prefixes
    for(int i = 0; i<=counter; i++){

    prefix = malloc(256);
    postfix = malloc(256);
    sprintf(postfix, "%d", counter);
    sprintf(prefix, "%d", i);
    strcat(prefix, line);
    strcat(prefix, postfix);
	  checkPassword(prefix, false);
    free(prefix);
    free(postfix);
    }

	}

  counter++;
  }
  return NULL;
}
void *oneWord2(){
  char* line = malloc(256);
//check without prefixes


//check with numbers
  int counter = 0;
  while(1){

    if(counter == 0){
for(int i=0;i<dictionaryLength; i++){

  strcpy(line,dictionary[i] );
    for(int k = 0; k< strlen(line); k++){

      line[k] = toupper(line[k]);
    }
    checkPassword(line, false);
	}
    }
  for (int j = 0; j< dictionaryLength; j++)
  {

    strcpy(line,dictionary[j] );
    for(int k = 0; k< strlen(line); k++){
      line[k] = toupper(line[k]);
    }
    //prefix
    char *prefix = malloc(256);
    char *postfix = malloc(256);
    sprintf(prefix, "%d", counter);
    strcat( prefix, line);
	  checkPassword(prefix, false);
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
	  checkPassword(prefix, false);
    free(prefix);
    free(postfix);
    }

    //postfix
    prefix = malloc(256);
    postfix = malloc(256);
    sprintf(postfix, "%d", counter);
    strcat(line, postfix);
    checkPassword(line, false);
    free(postfix);

    //postfix with all less prefixes
    for(int i = 0; i<=counter; i++){

    prefix = malloc(256);
    postfix = malloc(256);
    sprintf(postfix, "%d", counter);
    sprintf(prefix, "%d", i);
    strcat(prefix, line);
    strcat(prefix, postfix);
	  checkPassword(prefix, false);
    free(prefix);
    free(postfix);
    }

	}

  counter++;
  }
  return NULL;
}
void *twoWords0(){
  char* line;
  char* secondLine;
//check with numbers
  
  for(int j=0;j<dictionaryLength; j++){

    for(int i=0; i<dictionaryLength; i++){

      line = malloc(256);
      secondLine = malloc(256);
      removeSpaces(line);
      removeSpaces(secondLine);
      strcpy(line,dictionary[j] );
      strcpy(secondLine,dictionary[i] );
      strcat(line, " ");
      strcat(line, secondLine);
      checkPassword(line, true);
      free(secondLine);
      free(line);
    
      
	}

    }

  return NULL;
}
void *consumer(){
         

  while(1){

    pthread_cond_wait(&cond, &mutex3);
    printf("Password for %s is %s\n",newestMail, newestPassword);
    

  }
        

return NULL;
}