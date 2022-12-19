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
		
		char *newFile = malloc(256);
		scanf("%s", newFile);
		// printf("%s", newFile);
		pthread_mutex_lock(&mutex1);
		pthread_mutex_lock(&mutex2);
		pthread_mutex_lock(&mutex3);
		pthread_mutex_lock(&mutex4);
		
		
		free(passwords);
		free(dictionary);
		free(newestMail);
		free(newestPassword);
		dictionaryLength = 0;
		passwordToBreakLength = 0;
		numberOfPasswords = 0;
		passwordsFileName = malloc(256);
		strcpy(passwordsFileName, newFile);
		printf("New file: %s \n", passwordsFileName);
		readFromFiles();
		for(int i =0; i<4; i++){
			reset[i] = 1;
		}
		pthread_mutex_unlock(&mutex1);
		pthread_mutex_unlock(&mutex2);
		pthread_mutex_unlock(&mutex3);
		pthread_mutex_unlock(&mutex4);
		
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
	for(int i =0; i<4; i++){
			reset[i] = 0;
		}
	struct thread_args args;
	
	
	

 
 
	// char * dictionaryFileName = "tests/test-dict-large.txt";
	// char* passwordsFileName = "tests/test-data5.txt";
	passwordsFileName = malloc(256);
	dictionaryFileName = "tests/test-dict-mini.txt";
	passwordsFileName = strdup("tests/test-data1-local.txt");

	numberOfPasswords = 0;
	newestPassword = malloc(sizeof(char*));
	readFromFiles(dictionaryFileName, passwordsFileName);
	pthread_mutex_unlock(&mutex1);
	pthread_mutex_unlock(&mutex2);
	pthread_mutex_unlock(&mutex3);
	pthread_mutex_unlock(&mutex4);
	pthread_create(&threadC, NULL, consumer, NULL);
	
	pthread_create(&thread1, NULL, oneWord0, NULL);
	
	pthread_create(&thread2, NULL, oneWord1, NULL);
	pthread_create(&thread3, NULL, oneWord2, NULL);
	pthread_create(&thread4, NULL, twoWords0, NULL);
	pthread_create(&threadF, NULL, changeFile, NULL);
 while (1) ;
 pthread_join(threadF, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);
	pthread_join(threadC, NULL);
	

	pthread_mutex_destroy(&mutex1);
	pthread_mutex_destroy(&mutex2);
	pthread_mutex_destroy(&mutex3);
pthread_mutex_destroy(&mutex4);
	free(passwords);
	free(dictionary);
	free(passwordsToBreak);
    return 0;
}