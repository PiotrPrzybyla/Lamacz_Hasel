#include <openssl/evp.h>
#include <string.h>
#include <stdio.h>

#define MAX_PASSWORD_LIST_SIZE 1000

struct User{
	char* hashedPassword;
	char* mail;
	char* username;
};
void removeSpaces(char *str)
{
    // To keep track of non-space character count
    int count = 0;
 
    // Traverse the given string. If current character
    // is not space, then place it at index 'count++'
    for (int i = 0; str[i]; i++)
        if (str[i] != '\t' && str[i] != ' ')
            str[count++] = str[i]; // here count is
                                   // incremented
    str[count] = '\0';
}

void separateStringBySpace(char* input, struct User* user)
{
  // Use strtok to split the input string by space characters
  char* token = strtok(input, " ");
  int counter = 0;
  while (token != NULL)
  {
    // Print the current token to the console
    // printf("%s\n", token);
	removeSpaces(token);
	if(counter == 1){
		user->hashedPassword = token;
	} 
	if(counter == 2){
		user->mail = token;
	}
	if(counter == 3){ 
		user->username = token;
	}
    // Get the next token
    token = strtok(NULL, " ");
	counter++;
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
//małe litery
void oneWord0(char *dictionaryFileName, char *passwordsFileName){
 FILE *dictionaryFile = fopen(dictionaryFileName, "r");
 
  if (dictionaryFile == NULL)
  {
    printf("Failed to open the file: %s\n", dictionaryFileName);
    return;
  }
  // Read the file line by line
  char line[256];
  char passwordLine[256];
  char md5[33]; // 32 characters + null terminator

  while (fgets(line, sizeof(line), dictionaryFile))
  {
    // Print the line to the console
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
	
  }

  // Close the file
  fclose(dictionaryFile);
  
//pierwsza wielka litera
void oneWord1(){}
//wszystkie wielkie
void oneWord2(){}
void twoWords(){}
void consument(){}

int main(){
    // const char *test = "Wrong99";
	char *dictionaryFileName = "tests/test-dict-mini.txt";
	char *passwordsFileName = "tests/test-data1-local.txt";
	oneWord0(dictionaryFileName, passwordsFileName);
	// char md5[33]; // 32 characters + null terminator
	// bytes2md5(test, strlen(test), md5);
	// printf("%s ======================> %s\n", test, md5);
    return 0;
}