#ifndef MAIN_H
#define MAIN_H

														/*DEFINITION*/
#define MAX_BUFFER 1000
#define TRUE_STATE 1
#define FALSE_STATE 0
#define STACK 0
#define QUEUE 1
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
/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - Opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct Global_Var - contain all needed variables
 * @fd: file name
 * @buffer: the buffer take line by line
 * @opcode: the opcode
 * @run: the structure contain all supported function with it address
 * @top: point to the head of the stack double linked list
 * @line_number: the line number
 * @mode: 0 if it stack and 1 if it queue
*/
typedef struct Global_Var
{
	FILE *fd;
	char *buffer;
	char *opcode;
	instruction_t *run;
	stack_t *top;
	unsigned int line_number;
	int mode;
} vars_t;


extern vars_t file_var;


														/*PROTOTYPE*/
void start(vars_t *file_var);
int read_line(FILE *file);
void free_all(void);
int excute_func(vars_t *file_var);
instruction_t *creat_instruc();
int getnum(char *str, int line);
char *rm_space(char *buffer);
int isNumber(char *str);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

#endif /*MAIN_H*/
