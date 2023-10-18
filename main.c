#include "main.h"
/**
 * main - Start LIFO, FILO program
 * @ac: count arguments
 * @av: arguments
 * Return: 0 Success, 1 Failed
 */
vars var;
int main(int ac, char **av)
{
	char *opcode;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (start_vars(&var) != 0)
		return (EXIT_FAILURE);

	var.file = fopen(av[1], "r");
	if (!var.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		free_all();
		return (EXIT_FAILURE);
	}
	var.buff = (char *)malloc(var.tmp);
	if (!var.buff)
	{
		fprintf(stderr, "Memory allocation failed\n");
		free_all();
		return (EXIT_FAILURE);
	}
	while (fgets(var.buff, var.tmp, var.file) != NULL)
	{
		opcode = strtok(var.buff, " \r\t\n");
		if (opcode != NULL)
			if (call_funct(&var, opcode) == EXIT_FAILURE)
			{
				free_all();
				return (EXIT_FAILURE);
			}
		var.line_number++;
	}

	free_all();

	return (EXIT_SUCCESS);
}
