#include "shell.h"

/**
 * _eratoi - the function must convert a string to an integer
 * @b: the string should be converted
 * Return: 0 if no numbers found in string, converted number otherwise
 * -1 on error
 */
int _eratoi(char *b)
{
	int i = 0;
	unsigned long int result = 0;

	if (*b == '+')
		b++;  /* TODO: why does this make main return 255? */
	for (i = 0;  b[i] != '\0'; i++)
	{
		if (b[i] >= '0' && b[i] <= '9')
		{
			result *= 10;
			result += (b[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_ero -  print an error message to be printed
 * @info: parameter & return info structure
 * @estr: string containing specify error type
 * Return: 0 if no numbers found in string, converted number otherwise
 * -1 on error
 */
void print_ero(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_b - must print function print a decimal (integer) number (base 10)
 * @input: the input
 * @fd: filedescriptor to written to
 * Return: number of characters to be printed
 */
int print_b(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convet_numba - converter function
 * @num: number
 * @base: base
 * @flags: argument flag
 * Return: string
 */
char *convet_numba(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * rmov_comment - printed function replace first instance of '#' with '\0'
 * @buf: address of the string to be modifie
 * Return: Always 0;
 */
void rmov_comment(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
