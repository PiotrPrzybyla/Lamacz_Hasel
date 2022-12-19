#include <openssl/evp.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include "producers.h"
#include "globals.h"



void* changeFile(){
    while(1){
		free(passwordsFileName);
		passwordsFileName = malloc(1024);
		dictionaryFileName = "tests/test-dict-large.txt";
		scanf("%s", passwordsFileName);
		printf("%s", dictionaryFileName);
		pthread_cancel(thread1);
		pthread_cancel(thread2);
		pthread_cancel(thread3);
		pthread_cancel(thread4);
		pthread_cancel(threadC);
		pthread_mutex_lock(&mutex1);
		pthread_mutex_lock(&mutex2);
		pthread_mutex_lock(&mutex3);
		pthread_mutex_lock(&mutex4);
		numberOfPasswords = 0;
		newestPassword = malloc(sizeof(char*));
		readFromFiles(dictionaryFileName, passwordsFileName);

		pthread_mutex_unlock(&mutex1);
		pthread_mutex_unlock(&mutex2);
		pthread_mutex_unlock(&mutex3);
		pthread_mutex_unlock(&mutex4);
		rcC = pthread_create(&threadC, NULL, consumer, NULL);
	
	rc1 = pthread_create(&thread1, NULL, oneWord0, NULL);
	
	rc2 = pthread_create(&thread2, NULL, oneWord1, NULL);
	rc3 = pthread_create(&thread3, NULL, oneWord2, NULL);
	rc4 = pthread_create(&thread4, NULL, twoWords0, NULL);
	}
}
void handle_sigint(int sig)
{
showAllPasswords();
}
int main(int argc, char **argv){
	 signal(SIGINT, handle_sigint);

	pthread_mutex_init(&mutex1, NULL);
	pthread_mutex_init(&mutex2, NULL);
	pthread_mutex_init(&mutex3, NULL);
	pthread_mutex_init(&mutex4, NULL);

	pthread_mutex_lock(&mutex1);
	pthread_mutex_lock(&mutex2);
	pthread_mutex_lock(&mutex3);
	pthread_mutex_lock(&mutex4);
	struct thread_args args;
	
	
	

 
 
	char * dictionaryFileName = "tests/test-dict-large.txt";
	char* passwordsFileName = "tests/test-data5.txt";
	// dictionaryFileName = "tests/test-dict-mini.txt";
	// passwordsFileName = "tests/test-data1-local.txt";

	numberOfPasswords = 0;
	newestPassword = malloc(sizeof(char*));
	readFromFiles(dictionaryFileName, passwordsFileName);
	pthread_mutex_unlock(&mutex1);
	pthread_mutex_unlock(&mutex2);
	pthread_mutex_unlock(&mutex3);
	pthread_mutex_unlock(&mutex4);
	rcC = pthread_create(&threadC, NULL, consumer, NULL);
	
	rc1 = pthread_create(&thread1, NULL, oneWord0, NULL);
	
	rc2 = pthread_create(&thread2, NULL, oneWord1, NULL);
	rc3 = pthread_create(&thread3, NULL, oneWord2, NULL);
	rc4 = pthread_create(&thread4, NULL, twoWords0, NULL);
	rcF = pthread_create(&threadF, NULL, changeFile, NULL);
 while (1) ;
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);
	pthread_join(threadC, NULL);
	pthread_join(threadF, NULL);

	pthread_mutex_destroy(&mutex1);
	pthread_mutex_destroy(&mutex2);
	pthread_mutex_destroy(&mutex3);
pthread_mutex_destroy(&mutex4);
	free(passwords);
	free(dictionary);
	free(passwordsToBreak);
    return 0;
}