#include "push_swap.h"

int	error(t_pushswap *stack, char **free_me, int *free_me_2)
{
	if (stack)
		freeall(stack);
	if (free_me)
		freedoublechar(free_me);
	if (free_me_2)
		free(free_me_2);
	write(1, "Error\n", 7);
	exit(69);
	return (420);
}
