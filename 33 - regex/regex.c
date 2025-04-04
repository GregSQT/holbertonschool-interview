#include "regex.h"

/**
 * regex_match - Checks if string matches regex pattern
 * @s1: input string
 * @s2: input regex pattern
 * Return: 1 if inputs match, 0 otherwise
 */
int regex_match(char const *s1, char const *s2)
{
	if (!*s1 && !*s2)
		return (1);
	if (*s1 == *s2 || (*s2 == '.' && *(s2 + 1) != '*'))
		return (regex_match(s1 + 1, s2 + 1));
	if (*s2 == '.' && *(s2 + 1) == '*')
		return ((regex_match(s1, s2 + 2)) || (regex_match(s1 + 1, s2)));
	if (*s2 == '*')
		return (regex_match(s1, s2 + 1) || (regex_match(s1 + 1, s2)));
	if (*(s2 + 1) == '*')
		return (regex_match(s1, s2 + 2));
	return (0);
}
