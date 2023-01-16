#include "push_swap.h"

void	freedoublechar(char **tab)
{
	int	i;

	i = 0; 
	while (tab[i])
	{
		free(tab[i]);
		++i;
	}
	free(tab);
}

void	freeall(t_pushswap *pushswap)
{
	if (pushswap->un_sorted)
		free(pushswap->un_sorted);
	if (pushswap->stack_a)
		free(pushswap->stack_a);
	if (pushswap->stack_b)
		free(pushswap->stack_b);
	if (pushswap->sorted)
		free(pushswap->sorted);
}
