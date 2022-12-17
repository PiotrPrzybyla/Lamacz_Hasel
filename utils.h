#include <openssl/evp.h>
#include <string.h>
#include <stdio.h>
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

void separateStringBySpace(char* inputt, struct User* user)
{
  // Use strtok to split the input string by space characters
  char* input = malloc(1024);
  strncpy(input, inputt, 1024);
  char* token = strtok(input, " ");
  
  int counter = 0;
  while (token != NULL)
  {

	removeSpaces(token);

	if(counter == 1){
		user->hashedPassword = token;
	}
	if(counter == 3){ 
		user->username = token;
	}
    if(counter == 2){
		user->mail = token;
        
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

void checkPassword( char* password){
    char md5[33]; // 32 characters + null terminator
    removeSpaces(password);

    for(int k = 0; k<passwordToBreakLength; k++){
        pthread_mutex_lock(&mutex);
       
		bytes2md5(password, strlen(password), md5);
       
		struct User user;

        
		separateStringBySpace(passwordsToBreak[k], &user);

		if(compareStrings(md5, user.hashedPassword)){
            (numberOfPasswords)++;
			passwords = realloc(passwords, (numberOfPasswords) * sizeof(char*));
             
            passwords[(numberOfPasswords) -1] = strdup(password);
            mails = realloc(mails, (numberOfPasswords) * sizeof(char*));
            mails[(numberOfPasswords) -1] = strdup(user.mail);
            newestPassword = strdup(password);
            newestMail = mails[(numberOfPasswords) -1];
            pthread_cond_signal(&cond);
            
           
            
      }
      pthread_mutex_unlock(&mutex);
    }
   
}
void readFromFiles(char* dictionaryFileName, char* passwordsFileName){
    dictionaryLength = 0;
    passwordToBreakLength = 0;
    FILE *dictionaryFile = fopen(dictionaryFileName, "r");
    if (dictionaryFile == NULL)
  {
    printf("Failed to open the file: %s\n", dictionaryFileName);
    return;
  }
  // Read the file line by line
  char *line = malloc(32);
  char passwordLine[256];

  while (fgets(line, sizeof(line), dictionaryFile))
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
    passwordsToBreak[passwordToBreakLength -1] = strdup(passwordLine);
   
 }
 fclose(dictionaryFile);
 fclose(passwordFile);
}