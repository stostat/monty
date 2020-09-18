#include "monty.h"

/**
 * _pint - prints items on top of stack
 * @stack: node structure
 * @numline: line number
 * Return: void
 */
void _pint(stack_t **stack, unsigned int numline)
{
	if (!*stack)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", numline);
		free_tokens(vari.token);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * _nop - does nothing
 * @stack: node structure
 * @numline: line number
 * Return: void
 */
void _nop(stack_t **stack, unsigned int numline)
{
	(void)**stack;
	(void)numline;
}
/**
 * free_close - closes file, deletes stack
 * @stack: node structure
 * Return: Nothing
 */
void free_close(stack_t **stack)
{
	stack_t *tmp = *stack;

	if (*stack)
	{
		while (*stack)
		{
			*stack = (*stack)->next;
			free(tmp);
			tmp = *stack;
		}
	}
	fclose(vari.monty_file);
}

