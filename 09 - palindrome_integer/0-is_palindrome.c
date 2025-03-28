#include "palindrome.h"
/**
 * is_palindrome - Check if int is palindrome
 * @n: input
 * Return: 1 if true, 0 if false
 */

int is_palindrome(unsigned long n)
{
	unsigned long first, last, divide = 1;

	while (n / divide >= 10)
		divide *= 10;

	while (n != 0)
	{
		first = n / divide;
		last = n % 10;

		if (first != last)
			return (0);

		n = (n % divide) / 10;

		divide /= 100;
	}
	return (1);
}