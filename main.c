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
	
	
	
	pthread_t thread1, thread2, thread3, thread4, threadC;
	int rc1,rc2,rc3,rc4,rcC;
 
 
	char * dictionaryFileName = "tests/test-dict-mini.txt";
	char* passwordsFileName = "tests/test-data1.txt";
	

	numberOfPasswords = 0;
	newestPassword = malloc(sizeof(char*));
	readFromFiles(dictionaryFileName, passwordsFileName);
		// for(int i=0; i<dictionaryLength; i++){
		// 	printf("%s\n", dictionary[i]);
		// }
	    pthread_mutex_unlock(&mutex);

	rcC = pthread_create(&threadC, NULL, consumer, NULL);
	
	// rc1 = pthread_create(&thread1, NULL, oneWord0, NULL);
	
	// rc2 = pthread_create(&thread2, NULL, oneWord1, NULL);
	// rc3 = pthread_create(&thread3, NULL, oneWord2, NULL);
	rc4 = pthread_create(&thread4, NULL, twoWords0, NULL);
	pthread_join(thread4, NULL);
	// pthread_join(thread1, NULL);
	// pthread_join(thread2, NULL);
	// pthread_join(thread3, NULL);
	
	pthread_join(threadC, NULL);
	
	pthread_mutex_destroy(&mutex);
	free(passwords);
	free(dictionary);
	free(passwordsToBreak);
    return 0;
}