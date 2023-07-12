#include "monty.h"

/**
 * read_line - read one line at a time
 * @file: the file
 * Return: buffer to the line
*/

int read_line(FILE *file)
{
	char *tmp;

	tmp = file_var.buffer;
	file_var.buffer = fgets(file_var.buffer, MAX_BUFFER, file);
	if (!file_var.buffer)
		free(tmp);
	file_var.opcode = rm_space(file_var.buffer);
	if (file_var.opcode != NULL)
	{
		file_var.line_number++;
		if (!file_var.opcode[0] || file_var.opcode[0] == '#')
			strcpy(file_var.opcode, "nop");
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
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
	if (new_buffer[idx - 1] == '\n' || new_buffer[idx - 1] == ' ')
		idx--;
	if (new_buffer[idx - 1] == ' ')
		idx--;
	new_buffer[idx] = '\00';
	return (new_buffer);
}
