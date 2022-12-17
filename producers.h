#include <openssl/evp.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "utils.h"

//małe litery
void *oneWord0(void *arg){
 struct thread_args *args = (struct thread_args *)arg;
//check without prefixes
for(int i=0;i<dictionaryLength; i++){
     checkPassword(dictionary[i], args->numberOfPasswords);
	}

//check with numbers
  int counter = 0;
  while(counter<100){
  for (int j = 0; j< dictionaryLength; j++)
  {
    //prefix
    char *prefix = malloc(256);
    char *postfix = malloc(256);
    sprintf(prefix, "%d", counter);
    strcat( prefix, dictionary[j]);
	  checkPassword(prefix, args->numberOfPasswords);
    free(prefix);
    free(postfix);

    //prefix with all less postfixes
    for(int i = 0; i<=counter; i++){
    prefix = malloc(256);
    postfix = malloc(256);
    sprintf(prefix, "%d", counter);
    sprintf(postfix, "%d", i);
    strcat( prefix, dictionary[j]);
    strcat(prefix, postfix);
	  checkPassword(prefix, args->numberOfPasswords);
    free(prefix);
    free(postfix);
    }

    //postfix
    prefix = malloc(256);
    postfix = malloc(256);
    char* line = malloc(256);
    strcpy(line, dictionary[j]);
    sprintf(postfix, "%d", counter);
    strcat(line, postfix);
    checkPassword(line, args->numberOfPasswords);
    free(postfix);

    //postfix with all less prefixes
    for(int i = 0; i<=counter; i++){
    prefix = malloc(256);
    postfix = malloc(256);
    sprintf(postfix, "%d", counter);
    sprintf(prefix, "%d", i);
    strcat(prefix, dictionary[j]);
    strcat(prefix, postfix);
	  checkPassword(prefix, args->numberOfPasswords);
    free(prefix);
    free(postfix);
    }

	}

  counter++;
  }
  return NULL;
}
void *oneWord1(void *arg){
  char* line = malloc(256);
 struct thread_args *args = (struct thread_args *)arg;
//check without prefixes
for(int i=0;i<dictionaryLength; i++){
  strcpy(line,dictionary[i] );
    line[0] = toupper(line[0]);
    checkPassword(line, args->numberOfPasswords);
	}

//check with numbers
  int counter = 0;
  while(counter<100){
  for (int j = 0; j< dictionaryLength; j++)
  {
    strcpy(line,dictionary[j] );
    line[0] = toupper(line[0]);
    //prefix
    char *prefix = malloc(256);
    char *postfix = malloc(256);
    sprintf(prefix, "%d", counter);
    strcat( prefix, line);
	  checkPassword(prefix, args->numberOfPasswords);
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
	  checkPassword(prefix, args->numberOfPasswords);
    free(prefix);
    free(postfix);
    }

    //postfix
    prefix = malloc(256);
    postfix = malloc(256);
    sprintf(postfix, "%d", counter);
    strcat(line, postfix);
    checkPassword(line, args->numberOfPasswords);
    free(postfix);

    //postfix with all less prefixes
    for(int i = 0; i<=counter; i++){
    prefix = malloc(256);
    postfix = malloc(256);
    sprintf(postfix, "%d", counter);
    sprintf(prefix, "%d", i);
    strcat(prefix, line);
    strcat(prefix, postfix);
	  checkPassword(prefix, args->numberOfPasswords);
    free(prefix);
    free(postfix);
    }

	}

  counter++;
  }
  return NULL;
}
void *oneWord2(void *arg){
  char* line = malloc(256);
 struct thread_args *args = (struct thread_args *)arg;
//check without prefixes
for(int i=0;i<dictionaryLength; i++){
  strcpy(line,dictionary[i] );
    for(int k = 0; k< strlen(line); k++){
      line[k] = toupper(line[k]);
    }
    checkPassword(line, args->numberOfPasswords);
	}

//check with numbers
  int counter = 0;
  while(counter<100){
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
	  checkPassword(prefix, args->numberOfPasswords);
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
	  checkPassword(prefix, args->numberOfPasswords);
    free(prefix);
    free(postfix);
    }

    //postfix
    prefix = malloc(256);
    postfix = malloc(256);
    sprintf(postfix, "%d", counter);
    strcat(line, postfix);
    checkPassword(line, args->numberOfPasswords);
    free(postfix);

    //postfix with all less prefixes
    for(int i = 0; i<=counter; i++){
    prefix = malloc(256);
    postfix = malloc(256);
    sprintf(postfix, "%d", counter);
    sprintf(prefix, "%d", i);
    strcat(prefix, line);
    strcat(prefix, postfix);
	  checkPassword(prefix, args->numberOfPasswords);
    free(prefix);
    free(postfix);
    }

	}

  counter++;
  }
  return NULL;
}
