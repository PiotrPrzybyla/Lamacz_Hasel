#include <pthread.h>
pthread_mutex_t mutex1, mutex2, mutex3, mutex4;
pthread_cond_t cond;
char **passwords;
char **dictionary;
char **passwordsToBreak;
char **mailsToBreak;
char **mails;
int dictionaryLength;
int passwordToBreakLength;
int numberOfPasswords;
char *newestPassword;
char *newestMail;
pthread_t thread1, thread2, thread3, thread4, threadC;
