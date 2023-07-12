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


/**
 * sub - sub the top element from the previous one
 * @stack: the stack
 * @line_number: the line which are excuted
*/
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (!stack || !tmp || !tmp->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp->next->n -= tmp->n;
	pop(stack, line_number);
}


/**
 * _div - division the top two element (top2/top1)
 * @stack: the stack
 * @line_number: the line which are excuted
*/
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (!stack || !tmp || !tmp->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n",
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
	tmp->next->n /= tmp->n;
	pop(stack, line_number);
}


/**
 * mul - multiply top two element by merge them to one
 * @stack: the stack
 * @line_number: the line which are excuted
*/
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (!stack || !tmp || !tmp->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp->next->n *= tmp->n;
	pop(stack, line_number);
}
