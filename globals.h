#include <pthread.h>

pthread_mutex_t mutex;
char **passwords;
char **dictionary;
char **passwordsToBreak;
int dictionaryLength;
int passwordToBreakLength;