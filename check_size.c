#include "main.h"

/**
 * check_string - checks how many characters a string has
 * @string
 * Return: Number of characters
 */

int check_string(char *string)
{
	int i = 0;

	while (string[i] != '\0')
		i++;
	return (i);
}
