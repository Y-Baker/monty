#include "monty.h"

/**
 * mod - modulas the top two element (top2/top1)
 * @stack: the stack
 * @line_number: the line which are excuted
*/
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (!stack || !tmp || !tmp->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	else if (tmp->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp->next->n %= tmp->n;
	pop(stack, line_number);
}


/**
 * pchar - print the char of the int in the top element according to asci
 * @stack: the stack
 * @line_number: the line which are excuted
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (!stack || !tmp)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if (__isascii(tmp->n))
		dprintf(STDOUT_FILENO, "%c\n", tmp->n);
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
}


/**
 * pstr -  prints the string starting at the top of the stack to the end
 * @stack: the stack
 * @line_number: the line which are excuted
*/
void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp;

	tmp = *stack;
	while (tmp && tmp->n > 0 && tmp->n < 128)
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");
}


/**
 * rotl - make the top one in the last
 * @stack: the stack
 * @line_number: the line which are excuted
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;

	tmp = *stack;
	if (!tmp)
		return;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		free_all();
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->next = NULL;
	new->n = tmp->n;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	pop(stack, line_number);
}


/**
 * rotr - make the last one is the top
 * @stack: the stack
 * @line_number: the line which are excuted
*/
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp;

	tmp = *stack;
	if (!tmp)
		return;
	while (tmp->next)
		tmp = tmp->next;
	(*stack)->prev = tmp;
	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	*stack = tmp;
}

