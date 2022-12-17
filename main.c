#include <openssl/evp.h>
#include <string.h>
#include <stdio.h>
#include "producers.h"


void consument(){}

int main(){
	char *dictionaryFileName = "tests/test-dict-mini.txt";
	char *passwordsFileName = "tests/test-data1-local.txt";
	oneWord1(dictionaryFileName, passwordsFileName);
    return 0;
}