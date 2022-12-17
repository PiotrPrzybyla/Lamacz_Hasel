#include <openssl/evp.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "producers.h"
#include "globals.h"

void consument(){}

int main(int argc, char **argv){

	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
	struct thread_args args;
	
	
	
	pthread_t thread1, thread2, thread3, threadC;
	int rc1,rc2,rc3,rcC;
 
 
	char * dictionaryFileName = "tests/test-dict-mini.txt";
	char* passwordsFileName = "tests/test-data1-local.txt";
	
	    
		// int *numberOfPasswords;
		// numberOfPasswords = malloc(sizeof(int));
		numberOfPasswords = 0;
		// args.numberOfPasswords = numberOfPasswords;
newestPassword = malloc(sizeof(char*));
	readFromFiles(dictionaryFileName, passwordsFileName);
	// for(int i = 0; i< (passwordToBreakLength) ; i++){
	// 	printf("%s\n", passwordsToBreak[i]);
	// }
	    pthread_mutex_unlock(&mutex);
	
	// printf("%s", passwords[0]);
	
	// 
	rcC = pthread_create(&threadC, NULL, consumer, NULL);
	
	rc1 = pthread_create(&thread1, NULL, oneWord0, NULL);
	
	rc2 = pthread_create(&thread2, NULL, oneWord1, NULL);
	rc3 = pthread_create(&thread3, NULL, oneWord2, NULL);
	
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	// pthread_cancel(threadC);
	pthread_join(threadC, NULL);
	
	// for(int i = 0; i< (*numberOfPasswords) ; i++){
	// 	printf("%s\n", passwords[i]);
	// }
	pthread_mutex_destroy(&mutex);
	free(passwords);
	free(dictionary);
	free(passwordsToBreak);
    return 0;
}