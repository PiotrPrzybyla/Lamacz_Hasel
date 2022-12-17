#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond;
char **passwords;
char **dictionary;
char **passwordsToBreak;
char **mails;
int dictionaryLength;
int passwordToBreakLength;
int numberOfPasswords;
char *newestPassword;
char *newestMail;