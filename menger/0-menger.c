#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 * @level: level of sponge to deaw
 */
void menger(int level)
{
	int i, j, k, l;
	char print;

	if (level < 0)
		return;

	for (i = 0; i < pow(3, level); i++)
	{
		for (j = 0; j < pow(3, level); j++)
		{
			print = '#';
			k = i;
			l = j;
			while (k > 0 || l > 0)
			{
				if (k % 3 == 1 && l % 3 == 1)
					print = ' ';
				k /= 3;
				l /= 3;
			}
			printf("%c", print);
		}
		printf("\n");
	}

}
