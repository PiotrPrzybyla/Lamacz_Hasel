#include "utils.h"
#define MAX_PASSWORD_LIST_SIZE 1000


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