#include "monty.h"

/**
 * push - push element to the stack
 * @stack: the stack
 * @line_number: the line which are excuted
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int num;

	num = getnum(file_var.opcode, line_number);
	tmp = *stack;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		free_all();
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (file_var.mode == STACK || !*stack)
	{
		new->n = num;
		new->prev = NULL;
		new->next = *stack;
		if (*stack)
			tmp->prev = new;
		tmp = new;
		file_var.top = new;
	}
	else if (file_var.mode == QUEUE)
	{
		new->n = num;
		new->next = NULL;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

/**
 * pall - print all element in the stack
 * @stack: the stack
 * @line_number: the line which are excuted
*/
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp;

	tmp = *stack;
	if (!stack || !tmp)
		return;
	while (tmp)
	{
		dprintf(STDOUT_FILENO, "%d\n", tmp->n);
		tmp = tmp->next;
	}
}


/**
 * pint - print the number in the top of the stack
 * @stack: the stack
 * @line_number: the line which are executed
*/
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (!stack || !tmp)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	dprintf(STDOUT_FILENO, "%d\n", tmp->n);
}



/**
 * pop - remove element from the stack
 * @stack: the stack
 * @line_number: the line which are executed
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next)
	{
		tmp = (*stack)->next;
		free(tmp->prev);
		tmp->prev = NULL;
		file_var.top = tmp;
	}
	else
	{
		free(*stack);
		file_var.top = NULL;
	}
}



/**
 * nop - do nothing
 * @stack: the stack
 * @line_number: the line which are executed
*/
void nop(stack_t **stack __attribute__((unused)), unsigned int line_number)
{
	(void) line_number;
}
