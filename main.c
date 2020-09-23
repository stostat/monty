#include "monty.h"

many vari = {NULL, NULL, NULL};

/**
 * main - main function
 * @ac: count of arguments
 * @av: vectors
 * Return: void
 */
int main(int ac, char *av[])
{
	char *line = NULL;
	size_t len = 0;
	int i = 1;
	char delimit[] = " \t\r\v\n$";
	stack_t *stack = NULL;

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	vari.monty_file = fopen(av[1], "r");
	if (!vari.monty_file)
	{
		dprintf(2, "Error: Can't open file %s %s", av[1], "\n");
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, vari.monty_file)) != -1)
	{
		vari.token = _strtok(line, delimit);
		check_monty(vari.token, i);
		i++;
	}
	free(line);
	free_close(&stack);
	exit(EXIT_SUCCESS);
}
