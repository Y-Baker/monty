#ifndef MAIN_H
#define MAIN_H

														/*DEFINITION*/
#define MAX_BUFFER 1000
#define TRUE_STATE 1
#define FALSE_STATE 0
#define _POSIX_C_SOURCE 200809L
														/*HEADER*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <ctype.h>


														/*STRUCTURE*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


typedef struct Global_Var
{
	FILE *fd;
	char *buffer;
	char *opcode;
	instruction_t *run;
	stack_t *top;
	unsigned int line_number;
} vars_t;


extern vars_t file_var;


														/*PROTOTYPE*/
void start_file(vars_t *file_var);
int read_line(FILE *file);
void free_all(void);
int excute_func(vars_t *file_var);
instruction_t *creat_instruc();
int getnum(char *str, int line);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

#endif /*MAIN_H*/
