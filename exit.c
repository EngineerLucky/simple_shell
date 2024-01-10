#include "shell.h"

/**
 * _strngcopy - the function must copy a string with a specified length
 * @dest: the destination string to copy to
 * @src: the source string to copy from
 * @m: the maximum number of characters to copy
 * Return: a pointer to the destination string
 */
char *_strngcopy(char *dest, char *src, int m)

{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < m - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < m)
	{
		j = i;
		while (j < m)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * _stringcat - function must concatenate two strings with a specified length
 * @dest: the first string to concatenate
 * @src: the second string to concatenate
 * @m: the maximum number of characters to use from the source
 * Return: a pointer to the concatenated string
 */
char *_stringcat(char *dest, char *src, int m)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < m)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < m)
		dest[i] = '\0';
	return (s);
}

/**
 * _stringchr - the function locates a character in a string
 * @m: the string to search
 * @c: the character to locate
 * Return: pointer to the first occurrence of the character in the string
 */
char *_stringchr(char m, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
