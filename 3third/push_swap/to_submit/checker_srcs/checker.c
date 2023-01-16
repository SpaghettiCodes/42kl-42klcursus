#include "checker.h"

void	freeall(t_pushswap *stacks)
{
	if (stacks->stack_a)
		free(stacks->stack_a);
	if (stacks->stack_b)
		free(stacks->stack_b);
}

int	checkdup(t_pushswap *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->total_size)
	{
		j = i + 1;
		while (j < stack->total_size)
		{
			if (stack->stack_a[i] == stack->stack_a[j])
				return(errorexit(stack, NULL, NULL));
			j++;
		}
		i++;
	}
	return(1);
}

int	is_solved(t_pushswap *pushswap)
{
	int	i;

	i = -1;
	if ((pushswap->a_size != pushswap->total_size) || pushswap->b_size != 0)
		return (0);
	while (++i < (pushswap->a_size - 1))
		if (pushswap->stack_a[i] > pushswap->stack_a[i+1])
			return (0);
	return (1);
}

void	init_pushswap(t_pushswap *init)
{
	init->a_size = 0;
	init->b_size = 0;
	init->stack_a = NULL;
	init->stack_b = NULL;
	init->total_size = 0;
}

int	main(int ac, char **av)
{
	t_pushswap	pushswap;

	if (ac < 2)
		return(errorexit(NULL, NULL, NULL));
	init_pushswap(&pushswap);
	fill(&pushswap, av, ac);
	checkdup(&pushswap);
	pushswap.a_size = pushswap.total_size;
	pushswap.stack_b = (int *) malloc (sizeof(int) * pushswap.total_size);
	pushswap.b_size = 0;
	listeninstruction(&pushswap);
	if (!is_solved(&pushswap))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	freeall(&pushswap);
	return(0);
}