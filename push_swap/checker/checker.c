#include "checker.h"

void	freeall(t_pushswap *stacks)
{
	free(stacks->stack_a);
	free(stacks->stack_b);
}

// simplest way to check duplicate as im lazy to sort it out again (:
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
				return(errorexit(stack));
			j++;
		}
		i++;
	}
	return(1);
}

void	fill(t_pushswap *stack, char **av, int ac)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	ac--;
	while (++i < ac)
		stack->stack_a[i] = ft_atoi(av[++j], stack);
	checkdup(stack);
}

int	is_solved(t_pushswap *pushswap)
{
	int	i;

	i = -1;
	if (pushswap->a_size != pushswap->total_size && pushswap->b_size == 0)
		return (0);
	while (++i < (pushswap->a_size - 1))
		if (pushswap->stack_a[i] > pushswap->stack_a[i+1])
			return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_pushswap	pushswap;

	if (ac < 2)
		return(errorexit(NULL));
	pushswap.total_size = (ac - 1);
	pushswap.stack_a = (int *) malloc (sizeof(int) * (ac - 1));
	pushswap.stack_b = (int *) malloc (sizeof(int) * (ac - 1));
	pushswap.a_size = pushswap.total_size;
	pushswap.b_size = 0;
	fill(&pushswap, av, ac);
	listeninstruction(&pushswap);
	if (!is_solved(&pushswap))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	freeall(&pushswap);
	return(0);
}