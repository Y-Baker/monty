#include "monty.h"

/**
 * excute_func - excute line
 * @file_var: the Global var
 * Return: 0 if success ,Otherwise 1
*/

int excute_func(vars_t *file_var)
{
	short i, idx = 0;
	char str[10];

	for (i = 0; file_var->run[i].f; i++)
	{
		while (file_var->opcode[idx] != ' ' && file_var->opcode[idx])
		{
			str[idx] = file_var->opcode[idx];
			idx++;
		}
		str[idx] = '\0';
		if (strcmp(str, file_var->run[i].opcode) == 0)
		{
			file_var->run[i].f(&(file_var->top), file_var->line_number);
			return (EXIT_SUCCESS);
		}
	}
	strcpy(file_var->opcode, str);
	return (EXIT_FAILURE);
}
