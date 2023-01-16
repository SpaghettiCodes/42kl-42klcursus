#include "push_swap.h"

// check duplicate, stack has to have a sorted array
int	checkdup(t_pushswap *stack)
{
	int	i;

	i = -1;
	while (++i < (stack->total_size - 1))
		if (stack->sorted[i] == stack->sorted[i+1])
			return (error(stack, NULL, NULL));
	return (1);
}

//testing purposes
void printstack(t_pushswap *stacks)
{
	printf("Stack A: ");
	for (int i = 0; i < stacks->a_size; i++)
	{
		printf("%d ", stacks->stack_a[i]);
	}
	printf("\n");

	printf("Stack B: ");
	if (stacks->b_size == 0)
		printf("EMPTY!");
	else
	{
		for (int i = 0; i < stacks->b_size; i++)
		{
			printf("%d ", stacks->stack_b[i]);
		}
	}
	printf("\n");
}

int	is_solved(int *tab, int tab_size)
{
	int	i;

	i = -1;
	while (++i < (tab_size - 1))
		if (tab[i] > tab[i+1])
			return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_pushswap pushswap; 

	if (ac < 2)
		return (69);
	init_struct(&pushswap);
	fill(&pushswap, av, ac);
	pushswap.sorted = int_dup(pushswap.un_sorted, pushswap.total_size);
	q_sort(pushswap.sorted, 0, (pushswap.total_size - 1));
	checkdup(&pushswap);
	if (!is_solved(pushswap.un_sorted, pushswap.total_size))
		solve(&pushswap);
	freeall(&pushswap);
	return (0);
}
