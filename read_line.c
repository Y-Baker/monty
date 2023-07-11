#include "monty.h"

/**
 * read_line - read one line at a time
 * @file: the file
 * Return: buffer to the line
*/

int read_line(FILE *file)
{
	int len;

	file_var.opcode = NULL;
	file_var.opcode = fgets(file_var.buffer, MAX_BUFFER, file);
	if (file_var.opcode != NULL)
	{
		len = strlen(file_var.opcode) - 1;
		file_var.line_number++;
		if (file_var.opcode[len] == '\n')
			file_var.opcode[len] = '\00';
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
