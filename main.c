#include <openssl/evp.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include "producers.h"
#include "globals.h"

void consument(){}

int main(){
	int *numberOfPasswords;
	struct thread_args args;
	numberOfPasswords = malloc(sizeof(int));
	*numberOfPasswords = 0;
	pthread_t thread1, thread2, thread3;
	int rc1,rc2,rc3;
 pthread_mutex_init(&mutex, NULL);
	char * dictionaryFileName = "tests/test-dict-mini.txt";
	char* passwordsFileName = "tests/test-data1-local.txt";
	args.numberOfPasswords = numberOfPasswords;
	readFromFiles(dictionaryFileName, passwordsFileName);
	// oneWord0(passwords, numberOfPasswords);
	// printf("%s", passwords[0]);
	rc1 = pthread_create(&thread1, NULL, oneWord0, (void *)&args);
	// rc2 = pthread_create(&thread2, NULL, oneWord1, NULL);
	// rc3 = pthread_create(&thread3, NULL, oneWord2, NULL);
	pthread_join(thread1, NULL);
	// pthread_join(thread2, NULL);
	// pthread_join(thread3, NULL);
	for(int i = 0; i< (*numberOfPasswords) ; i++){
		printf("%s\n", passwords[i]);
	}
	pthread_mutex_destroy(&mutex);
	free(numberOfPasswords);
	free(passwords);
    return 0;
}