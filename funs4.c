#include "monty.h"

/**
 * stack - change the mode to the stack mod
 * @stack: the stack
 * @line_number: the line which are executed
*/
void stack(stack_t **stack __attribute__((unused)), unsigned int line_number)
{
	(void) line_number;

	file_var.mode = STACK;
}


/**
 * queue - change the mod to the queue mod
 * @stack: the stack
 * @line_number: the line which are executed
*/
void queue(stack_t **stack __attribute__((unused)), unsigned int line_number)
{
	(void) line_number;

	file_var.mode = QUEUE;
}
