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


/*functions*/
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
int executeWithLogicalOperators(char **args);
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
/*printf family functions*/
int _snprintf(char *str, size_t size, const char *format, ...);
int _sprintf(char *str, const char *format, ...);
int _vsprintf(char *str, const char *fmt, va_list arg);
int my_vsnprintf(char *buf, size_t size, const char *format, va_list arg);
/*dynamic memoery allocations funcs*/
void *my_realloc(void *ptr, unsigned int size, unsigned int newsize);
/* vsprintf functions*/
char *s_itoa(int num, char *str);
int write_integer(char **str, int num);
int write_string(char **str, const char *s);
int write_char(char **str, char c);
int write_float(char **str, float num);
int write_float_decimal(char **str, double num);
int write_to_str(char **str, char type, va_list arg);
char parse_format_specifier(const char **p);
/* vsnprintf functions*/
void write_character(char **buf, char ch, size_t *remaining, int *written);
void write_str(char **buf, const char *str, size_t *remaining, int *written);
void write_int(char **buf, int value, size_t *remaining, int *written);
#endif
