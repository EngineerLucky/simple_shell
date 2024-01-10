#include "shell.h"

/**
 * _eput - the input string should be printed
 * @str: string to be printed
 * Return: Nothing should be returned
 */
void _eput(char *str)
{
	int b = 0;

	if (!str)
		return;
	while (str[b] != '\0')
	{
		_eputchar(str[b]);
		b++;
	}
}

/**
 * _eputcar - must write the character c to stderr
 * @b: The character to be printed
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputcar(char b)
{
	static int b;
	static char buf[WRITE_BUF_SIZE];

	if (b == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
	{
		write(2, buf, b);
		b = 0;
	}
	if (b != BUF_FLUSH)
		buf[b++] = b;
	return (1);
}

/**
 * _ptfd - must write the character b to be given to fd
 * @b: The character to be printed
 * @fd: The file descriptor to write
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _ptfd(char b, int fd)
{
	static int b;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || b >= WRITE_BUF_SIZE)
	{
		write(fd, buf, b);
		b = 0;
	}
	if (b != BUF_FLUSH)
		buf[b++] = b;
	return (1);
}

/**
 * _putfd - must print an input string to be printed
 * @str: the string to be printed
 * @fd: the file descriptor to write
 * Return: the number of chars put
 */
int _putfd(char *str, int fd)
{
	int b = 0;

	if (!str)
		return (0);
	while (*str)
	{
		b += _putfd(*str++, fd);
	}
	return (b);
}
