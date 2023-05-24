#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#define BUFFER_SIZE 1024
#define MAX_ARGS 100
#define MAX_ALIASES 100
#define BUFSIZE 1024
/*alias*/
typedef struct AliasNode
{
	char *aliasName;
	char *aliasValue;
	struct AliasNode *next;
} AliasNode;

extern int last_exit_status;
/*functions*/
void exitShell(int exitStatus);
int isComment(const char *line);
char *handleVariables(char *input);
extern char **environ;
int clear(void);
void printPrompt(void);
void check_exit(char **args);
void parseInput(char *buffer, char **args);
char *getAbsolutePath(char *command);
int executeCommand(char *cmd, char **args);
void printEnv(void);
int changeDirectory(char *directory);
int mySetEnv(char *var, char *value);
int myUnsetEnv(char *var);
void set_env(char **args);
void unset_env(char **args);
char **tokenize(char *str, char *delimiter);
/*string functions*/
unsigned int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strtok(char *str, const char *delim);
unsigned int check_match(char c, const char *str);
char *_strcat(char *dest, const char *src);
int _strcmpr(char *strcmp1, char *strcmp2);
char *_strdup(char *strtodup);
size_t _strcspn(const char *str1, const char *str2);
int _strncmp(const char *str1, const char *str2, size_t n);
int _atoi(char *str);
int int_to_string(char *str, int num);
void reverse_string(char *str, int length);
void write_string(char *dest, char *src, int len);
/*printf family functions*/
int _snprintf(char *str, size_t size, const char *format, ...);
int _sprintf(char *str, const char *format, ...);
/*dynamic memoery allocations funcs*/
void *my_realloc(void *ptr, unsigned int size, unsigned int newsize);
/* vsprintf functions*/
char *s_itoa(int num, char *str);
int write_integer(char **str, int num);
/*getline*/
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);
#endif
