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
	if (TRUE_STATE) /*stack*/
	{
		new->n = num;
		new->prev = NULL;
		new->next = *stack;
		if (*stack)
			tmp->prev = new;
		tmp = new;
		file_var.top = new;
	}

}

/**
 * pall - print all element in the stack
 * @stack: the stack
 * @line_number: the line which are excuted
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (!stack || !tmp)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	while (tmp)
	{
		dprintf(STDOUT_FILENO, "%d\n", tmp->n);
		tmp = tmp->next;
	}
}

