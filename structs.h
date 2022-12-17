struct User{
	char* hashedPassword;
	char* mail;
	char* username;
};
struct thread_args{
	 char *dictionaryFileName;
	char *passwordsFileName;
	int *numberOfPasswords;
};