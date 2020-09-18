#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct many_var - struct to header and FILE
 * @monty_file: file to be opened
 * @top: head of the stack
 * @token: tokenized token
  */
typedef struct many_var
{
	FILE *monty_file;
	stack_t *top;
	char **token;
} many;
extern many vari;

int ismonty(char *file);
int _strlen_recursion(char *s);
int _strcmp(char *s1, char *s2);
char **_strtok(char *str, char *delimiter);
int count_words(char *str, char *delimiter);
int count_letters(char *str, char *delimiter);
int _delimiters(char c, char *delimiter);
int check_monty(char **token, unsigned int numline);
void free_tokens(char **tokens);
int _atoi(char *s);

void free_close(stack_t **stack);
void _push(stack_t **stack, unsigned int numline);
void _nop(stack_t **stack, unsigned int numline);
void _add(stack_t **stack, unsigned int numline);
void _swap(stack_t **stack, unsigned int numline);
void _pop(stack_t **stack, unsigned int numline);
void _pint(stack_t **stack, unsigned int numline);
void _pall(stack_t **stack, unsigned int numline);

#endif

