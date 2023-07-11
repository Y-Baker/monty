#include "monty.h"

vars_t file_var;

/**
 * main - monty main function
 * @argc: the number of command line arguments
 * @argv: the vector of command line argument
 * Return: Always 0
*/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	start(&file_var);

	file_var.fd = fopen(argv[1], "r");
	if (!file_var.fd)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		free_all();
		return (EXIT_FAILURE);
	}
	while (!read_line(file_var.fd))
	{
		if (excute_func(&file_var))
		{
			dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n",
			file_var.line_number, file_var.opcode);
			free_all();
			return (EXIT_FAILURE);
		}
	}
	free_all();
	return (EXIT_SUCCESS);
}
