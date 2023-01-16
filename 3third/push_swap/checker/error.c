#include "checker.h"

int	errorexit(t_pushswap *stacks)
{
	if (stacks)
		freeall(stacks);
	write(2, "Error\n", 7);
	exit(69);
	return(420);
}