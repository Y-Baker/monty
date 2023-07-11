#include "monty.h"

/**
 * start_file - get vars type ready to start interpreter
 * @file_var: the global var
*/

void start_file(vars_t *file_var)
{
	file_var->fd = NULL;
	file_var->line_number = 0;
	file_var->buffer = NULL;
	file_var->opcode = NULL;
	file_var->top = NULL;
	file_var->run = creat_instruc();
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
	funs[3].opcode = NULL, funs[3].f = NULL;
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
	char *num;
	short i = 0;

	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] != ' ')
		{
			if (str[i + 1] >= '0' && str[i + 1] <= '9')
			{
				num = &str[i + 1];
				break;
			}
			else
			{
				dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line);
				free_all();
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
	return (atoi(num));
}


/**
 * rm_space - rmove spaces from buffer
 * @buffer: the buffer which has the string
 * Return: the new buffer
*/
char *rm_space(char *buffer)
{
	int i = 0;
	int idx = 0;
	int stat = TRUE_STATE;
	char *new_buffer;

	new_buffer = file_var.opcode;

	if (!buffer)
	{
		free(new_buffer);
		return (NULL);
	}
	while (buffer[i])
	{
		if (buffer[i] == ' ' && stat)
		{
			i++;
			continue;
		}
		else if (buffer[i] != ' ')
		{
			stat = FALSE_STATE;
			new_buffer[idx] = buffer[i];
		}
		else
		{
			stat = TRUE_STATE;
			new_buffer[idx] = ' ';
		}
		idx++;
		i++;
	}
	new_buffer[idx] = '\00';
	return (new_buffer);
}
