#include "monty.h"

/**
 * check_monty - checks each token for monty functions
 * @token: double pinter to each token
 * @numline: line number
 * Return: 1 on succes
 */
int check_monty(char **token, unsigned int numline)
{
	int i = 0;
	instruction_t monty[] = {{"pall", _pall}, {"pint", _pint}, {"pop", _pop},
	{"swap", _swap}, {"add", _add}, {"nop", _nop}, {"push", _push}, {NULL, NULL}};


	if (!*token)
	{
		dprintf(2, "USAGE: monty file\n");
		free_tokens(token);
		exit(EXIT_FAILURE);
	}

	while (monty[i].opcode)
	{
		if (_strcmp(token[0], monty[i].opcode) == 0)
		{
			(monty[i].f)(&vari.top, numline);
			return (0);
		}
		i++;
	}
	dprintf(2, "L%u: unknown instruction %s %s", numline, token[0], "\n");
	free_tokens(token);
	exit(EXIT_FAILURE);
}

/**
 * _push - adds node to head
 * @stack: node structure
 * @numline: line number
 * Return: void
 */
void _push(stack_t **stack, unsigned int numline)
{
	stack_t *temp = *stack;

	if (!vari.token[1] || !_atoi(vari.token[1]))
	{
		dprintf(2, "L%u: usage: push integer\n", numline);
		free_tokens(vari.token);
		exit(EXIT_FAILURE);
	}
	vari.top = malloc(1 * sizeof(stack_t));

	if (!vari.top)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	vari.top->n = _atoi(vari.token[1]);
	vari.top->next = temp;
	vari.top->prev = NULL;
	if (temp)
		temp->prev = vari.top;
	temp = vari.top;
}

/**
 * _pall - prints all items in stack
 * @stack: node structure
 * @numline: line number
 * Return: void
 */
void _pall(stack_t **stack, unsigned int numline)
{
	stack_t *temp = *stack;
	(void)numline;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
