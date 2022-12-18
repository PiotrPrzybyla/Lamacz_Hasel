#include <pthread.h>
pthread_mutex_t mutex1, mutex2, mutex3;
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