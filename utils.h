#include <openssl/evp.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include "structs.h"
#include "globals.h"

int compareStrings(char* str1, char* str2){
    int counter;
    if(sizeof(str1) < sizeof(str2)){
        counter = sizeof(str1);
    }else{
         counter = sizeof(str2);
    }
    for(int i=0;i<counter;i++){
        if(str1[i] != str2[i]) return 0;
    }
    return 1;
}
void removeNewLine(char *str){
     int count = 0;
      for (int i = 0; str[i]; i++)
        if (str[i]!='\n')
            str[count++] = str[i]; // here count is
                                   // incremented
    str[count] = '\0';
}
void removeSpaces(char *str)
{
    // To keep track of non-space character count
    int count = 0;
 
    // Traverse the given string. If current character
    // is not space, then place it at index 'count++'
    for (int i = 0; str[i]; i++)
        if (str[i] != '\t' && str[i] != ' ' && str[i]!='\n')
            str[count++] = str[i]; // here count is
                                   // incremented
    str[count] = '\0';
}

void separateStringBySpace(char* inputt, char** passwordToBreak, char** mailToBreak)
{
 //Use strtok to split the input string by space characters
  char* input = malloc(256);
  strncpy(input, inputt, 256);
  char* token = strtok(input, " ");
  
  int counter = 0;
  while (token != NULL)
  {

	removeSpaces(token);

	if(counter == 1){
		*passwordToBreak = token;
	}
    if(counter == 2){
		*mailToBreak = token;
        
	} 
    // Get the next token
    token = strtok(NULL, " ");
	counter++;
    // 
  }
  
}
void bytes2md5(const char *data, int len, char *md5buf) {
	EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
	const EVP_MD *md = EVP_md5();
	unsigned char md_value[EVP_MAX_MD_SIZE];
	unsigned int md_len, i;
	EVP_DigestInit_ex(mdctx, md, NULL);
	EVP_DigestUpdate(mdctx, data, len);
	EVP_DigestFinal_ex(mdctx, md_value, &md_len);
	EVP_MD_CTX_free(mdctx);
	for (i = 0; i < md_len; i++) {
		snprintf(&(md5buf[i * 2]), 16 * 2, "%02x", md_value[i]);
	}
}

void checkPassword( char* password, bool withSpaces){
    char md5[33]; // 32 characters + null terminator
    if(!withSpaces){
    removeSpaces(password);
    } 
    // printf("%s\n", password);
    
    for(int k = 0; k<passwordToBreakLength; k++){
        char *passwordToBreak = malloc(256);        
        
       strcpy(passwordToBreak,passwordsToBreak[k] );
      
		bytes2md5(password, strlen(password), md5);
       pthread_mutex_lock(&mutex3);
		if(compareStrings(md5, passwordToBreak)){
            bool alreadyExists = false;
            
            for(int j = 0; j<numberOfPasswords; j++){
            if(compareStrings(passwords[j], strdup(password))){
                    alreadyExists = true;
                }
           
            }
            if(!alreadyExists){
            (numberOfPasswords)++;
			passwords = realloc(passwords, (numberOfPasswords) * sizeof(char*));
             
            passwords[(numberOfPasswords) -1] = strdup(password);
            mails = realloc(mails, (numberOfPasswords) * sizeof(char*));
            mails[(numberOfPasswords) -1] = strdup(mailsToBreak[k]);
            newestPassword = strdup(password);
            newestMail = mails[(numberOfPasswords) -1];
            pthread_cond_signal(&cond);
            
            }
           
           
            
      }
      pthread_mutex_unlock(&mutex3);
      
    }
   
}
void readFromFiles(){
    dictionaryLength = 0;
    passwordToBreakLength = 0;
    
    FILE *dictionaryFile = fopen(dictionaryFileName, "r");
    if (dictionaryFile == NULL)
  {
    printf("Failed to open the file: %s\n", dictionaryFileName);
    return;
  }
  // Read the file line by line
  char *line = malloc(33);
  char passwordLine[256];

  while (fgets(line, 2 * sizeof(char*), dictionaryFile))
  { 
    dictionaryLength++;
    dictionary = realloc(dictionary, dictionaryLength * sizeof(char*));

    removeSpaces(line);
    dictionary[dictionaryLength -1] = strdup(line);
}
   
    FILE *passwordFile = fopen(passwordsFileName, "r");
 while(fgets(passwordLine, sizeof(passwordLine), passwordFile)){
    
    passwordToBreakLength++;
    passwordsToBreak = realloc(passwordsToBreak, passwordToBreakLength * sizeof(char*));
    mailsToBreak = realloc(mailsToBreak, passwordToBreakLength * sizeof(char*));
    separateStringBySpace(passwordLine, &passwordsToBreak[passwordToBreakLength -1], &mailsToBreak[passwordToBreakLength -1]);
   
 }
  
 fclose(dictionaryFile);
 fclose(passwordFile);

}
void showAllPasswords(){
    
     pthread_mutex_lock(&mutex3);
     printf("\n All passwords: \n");
    for(int i =0; i<numberOfPasswords; i++){
printf("Password for %s is %s\n",mails[i], passwords[i]);
    }
    printf("--------------------------------\n");
      pthread_mutex_unlock(&mutex3);
}
