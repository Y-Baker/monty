#include "monty.h"

/**
 * read_line - read one line at a time
 * @file: the file
 * Return: buffer to the line
*/

int read_line(FILE *file)
{
	int len;
	char *tmp;

	tmp = file_var.buffer;
	file_var.buffer = fgets(file_var.buffer, MAX_BUFFER, file);
	if (!file_var.buffer)
		free(tmp);
	file_var.opcode = rm_space(file_var.buffer);
	if (file_var.opcode != NULL)
	{
		len = strlen(file_var.opcode) - 1;
		file_var.line_number++;
		if (file_var.opcode[len] == '\n')
			file_var.opcode[len] = '\00';
		if (!file_var.opcode[0])
			strcpy(file_var.opcode, "nop");
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
