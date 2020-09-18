#include "monty.h"

/**
 * _pop - removes head
 * @stack: node structure
 * @numline: line number
 * Return: void
 */
void _pop(stack_t **stack, unsigned int numline)
{
	stack_t *temp = *stack;

	if (!(*stack))
	{
		dprintf(2, "L%d: can't pop an empty stack\n", numline);
		free_close(stack);
		exit(EXIT_FAILURE);
	}

	*stack = temp->next;
	if (temp->next != NULL)
		temp->next->prev = NULL;
	free(temp);
}

/**
 * _swap - swaps two firsts nodes
 * @stack: node structure
 * @numline: line number
 * Return: void
 */
void _swap(stack_t **stack, unsigned int numline)
{
	stack_t *temp = *stack;
	stack_t *aux = *stack;
	int i = 0;

	while (temp)
	{
		i++;
		temp = temp->next;
	}
	if (i > 0)
	{
		temp = *stack;
		aux = aux->next;
	}
	if (i < 2)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", numline);
		free_close(stack);
		exit(EXIT_FAILURE);
	}
	else if (i == 2)
	{
		temp->next = NULL;
		temp->prev = aux;
		aux->prev = NULL;
		aux->next = temp;
	}
	else
	{
		temp->next = aux->next;
		temp->prev = aux;
		aux->next->prev = temp;
		aux->prev = NULL;
		aux->next = temp;
	}
	*stack = aux;
}

/**
 * _add - sums two first nodes
 * @stack: node structure
 * @numline: line number
 * Return: void
 */
void _add(stack_t **stack, unsigned int numline)
{
	stack_t *temp = *stack;
	stack_t *aux = *stack;
	int i = 0;

	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	if (i < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", numline);
		free_close(stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	aux = aux->next;
	aux->n = temp->n + temp->next->n;
	free(temp);
	aux->prev = NULL;
	*stack = aux;
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
