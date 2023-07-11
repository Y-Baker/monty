#include "monty.h"

/**
 * swap - swap two element
 * @stack: the stack
 * @line_number: the line which are excuted
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (!stack || !tmp || !tmp->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp->n += tmp->next->n;
	tmp->next->n = tmp->n - tmp->next->n;
	tmp->n -= tmp->next->n;
}


/**
 * add - merge the two top element
 * @stack: the stack
 * @line_number: the line which are excuted
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (!stack || !tmp || !tmp->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp->next->n += tmp->n;
	pop(stack, line_number);
}
