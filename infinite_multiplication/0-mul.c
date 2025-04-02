#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * error - prints error messsage and exits with code 98
 */
void error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}
/**
 * length - gets length of array
 * @n: array
 * Return: length of array
 */
int length(char *n)
{
	int len = 0;
	char *temp = n;

	while (*temp)
	{
		len++;
		temp++;
	}

	return (len);
}
/**
 * multiply - multiply two strings representing numbers
 * @num1: first number
 * @num2: second number
 * Return: product of the two numbers
 */
int multiply(char *num1, char *num2)
{
	int len1 = length(num1);
	int len2 = length(num2);
	int i, j, n1, n2, sum;
	int *result = malloc(len1 + len2);

	if (!result)
		return (1);
	for (i = 0; i < len1 + len2; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = n1 * n2 + result[i + j + 1];
			result[i + j] += sum / 10;
			result[i + j + 1] = sum % 10;
		}
	}
	i = 0;
	while (result[i] == 0)
		i++;
	while (i < (len1 + len2))
		_putchar(result[i++] + '0');
	_putchar('\n');
	return (0);
}
/**
 * check_input - checks if input is a number
 * @num: input array
 * Return: 1 if number, 0 if not
 */
int check_input(char *num)
{
	char *temp = num;

	while (*temp)
	{
		if (*temp < '0' || *temp > '9')
			return (0);
		temp++;
	}

	return (1);
}
/**
 * main - entry point
 * @argc: - number of arguments
 * @argv: - vector of arguments
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *num1 = argv[1];
	char *num2 = argv[2];

	if (argc != 3 || !check_input(num1) || !check_input(num2))
		error();

	if (*argv[1] == '0' || *argv[2] == '0')
	{
		_putchar('0');
		_putchar('\n');
	}

	return (multiply(num1, num2));
}
