#include "monty.h"

/**
 * ismonty - checks if a file has .m extension
 * @file: str to be checked
 * Return: 0 if no match found, 1 if succesful
 */
int ismonty(char *file)
{
	size_t len = _strlen_recursion(file) - 2;

	if (len < 2)
		return (0);
	return (_strcmp(file + len, ".m") == 0);
}

/**
 * _strlen_recursion - check the lenght of a string.
 * @s: char
 * Return: void.
 */

int _strlen_recursion(char *s)
{
	if (*s != '\0')
		return (1 + _strlen_recursion(s + 1));
	return (0);
}
/**
 * _strcmp - check the code for Holberton School students.
 * @s1: char1
 * @s2: char 2
 * Return: int
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; *(s1 + i) != '\0'; i++)
	{
		if (*(s1 + i) > *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
/**
 * _atoi - convert a string to an integer.
 *
 * @s: string to be reviewed
 *
 * Return: an integer from s or 0 if is not a number
 */

int _atoi(char *s)
{
	unsigned int runner, minus, num, letter, retrieved;

	runner = num = letter = retrieved = 0;
	minus = 1;

	while (s[runner])
	{
		if (s[runner] == 45)
			minus *= -1;
		if (s[runner] >= 48 && s[runner] <= 57)
		{
			retrieved = retrieved * 10 + (s[runner] - 48);
			num = 1;
		}
		if (!(s[runner] >= 48 && s[runner] <= 57))
		{
			if (num == 1)
				letter = 1;
		}
		if (letter == 1)
			break;
		runner++;
	}
	return (retrieved * minus);
}

