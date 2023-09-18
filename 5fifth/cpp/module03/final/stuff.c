#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	int	base = atoi(av[1]);

	for (int i = 0; i < base; ++i)
	{
		for (int j = 0; j < base; ++j)
			(j >= (base - i - 1)) ? printf("#") : printf(" ");
		printf("\n");
	}
}

