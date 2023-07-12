#include "monty.h"

/**
 * start - get vars type ready to start interpreter
 * @file_var: the global var
*/

void start(vars_t *file_var)
{
	file_var->fd = NULL;
	file_var->line_number = 0;
	file_var->buffer = NULL;
	file_var->opcode = NULL;
	file_var->top = NULL;
	file_var->run = creat_instruc();
	file_var->mode = STACK;
	file_var->buffer = malloc(MAX_BUFFER * sizeof(char));
	file_var->opcode = malloc(MAX_BUFFER * sizeof(char));
	if (!file_var->buffer || !file_var->opcode)
	{
		free_all();
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * free_all - free global vars
*/
void free_all(void)
{
	if (1)
		free(file_var.buffer);
	if (file_var.fd != NULL)
		fclose(file_var.fd);
	if (file_var.run != NULL)
		free(file_var.run);
	if (1)
		free(file_var.opcode);
	if (file_var.top != NULL)
	{
		while (file_var.top->next)
		{
			file_var.top = file_var.top->next;
			free(file_var.top->prev);
		}
		free(file_var.top);
	}
}

/**
 * creat_instruc - add all insruc
 * Return: the result
*/
instruction_t *creat_instruc()
{
	instruction_t *funs;

	funs = malloc(18 * sizeof(instruction_t));
	if (!funs)
	{
		free_all();
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	funs[0].opcode = "push", funs[0].f = push;
	funs[1].opcode = "pall", funs[1].f = pall;
	funs[2].opcode = "nop", funs[2].f = nop;
	funs[3].opcode = "pint", funs[3].f = pint;
	funs[4].opcode = "pop", funs[4].f = pop;
	funs[5].opcode = "swap", funs[5].f = swap;
	funs[6].opcode = "add", funs[6].f = add;
	funs[7].opcode = "sub", funs[7].f = sub;
	funs[8].opcode = "div", funs[8].f = _div;
	funs[9].opcode = "mul", funs[9].f = mul;
	funs[10].opcode = "mod", funs[10].f = mod;
	funs[11].opcode = "pchar", funs[11].f = pchar;
	funs[12].opcode = "pstr", funs[12].f = pstr;
	funs[13].opcode = "rotl", funs[13].f = rotl;
	funs[14].opcode = "rotr", funs[14].f = rotr;
	funs[15].opcode = "stack", funs[15].f = stack;
	funs[16].opcode = "queue", funs[16].f = queue;
	funs[17].opcode = NULL, funs[17].f = NULL;
	return (funs);
}

/**
 * getnum - get number for push
 * @str: the string
 * @line: the line number
 * Usage: push <num>
 * Return: the number
*/
int getnum(char *str, int line)
{
	char *num = NULL;
	short i = 0;

	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] != ' ')
		{
			if (str[i + 1] == '-' && str[i + 2] >= '0' && str[i + 2] <= '9')
			{
				num = &str[i + 1];
				break;
			}
			else if (str[i + 1] >= '0' && str[i + 1] <= '9')
			{
				num = &str[i + 1];
				break;
			}
			else
			{
				num = NULL;
				break;
			}
		}
		i++;
	}
	if (!isNumber(num))
		return (atoi(num));

	dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line);
	free_all();
	exit(EXIT_FAILURE);

}


/**
 * isNumber - check if all the string is number or not
 * @str: the string to checked
 * Return: 0 if success ,Otherwise 1
*/
int isNumber(char *str)
{
	int i = 0;

	if (!str)
		return (EXIT_FAILURE);

	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
			i++;
		else if (str[i] == ' ')
		{
			break;
		}
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
