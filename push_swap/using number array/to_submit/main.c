#include "push_swap.h"

void	freeall(t_pushswap *pushswap)
{
	if (pushswap->instructions)
		del_all(&pushswap->instructions);
	if (pushswap->un_sorted)
		free(pushswap->un_sorted);
	if (pushswap->stack_a)
		free(pushswap->stack_a);
	if (pushswap->stack_b)
		free(pushswap->stack_b);
	if (pushswap->sorted)
		free(pushswap->sorted);
}

int	error(t_pushswap *stack)
{
	if (stack)
		freeall(stack);
	write(1, "Error\n", 7);
	exit(69);
	return (420);
}

int	fill(t_pushswap *stack, char **av, int ac)
{
	int	i;
	int j;

	i = -1;
	j = 0;
	ac--;
	while (++i < ac)
		stack->un_sorted[i] = ft_atoi(av[++j], stack);
	return (1);
}

int	checkdup(t_pushswap *stack)
{
	int	i;

	i = -1;
	while (++i < (stack->total_size - 1))
		if (stack->sorted[i] == stack->sorted[i+1])
			return (error(stack));
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

void ft_bzero(int *array, int size)
{
	int i;
	
	i = -1; 
	while (++i < size)
		array[i] = 0;
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

	if (ac <= 1)
		return (error(NULL));
	pushswap.total_size = ac - 1;
	pushswap.stack_a = NULL;
	pushswap.stack_b = NULL;
	pushswap.instructions = NULL;

	pushswap.un_sorted = (int *) malloc ((ac - 1) * sizeof(int));
	fill(&pushswap, av, ac);
	pushswap.sorted = int_dup(pushswap.un_sorted, pushswap.total_size);
	q_sort(pushswap.sorted, 0, (pushswap.total_size - 1));
	checkdup(&pushswap);

	if (!is_solved(pushswap.un_sorted, pushswap.total_size))
		solve(&pushswap); // this would be the sorting algo
	
	printf("done\n");
	if (is_solved(pushswap.stack_a, pushswap.a_size))
		printf("SORTED!\n");
	else
		printf("NOT SORTED\n");
	printstack(&pushswap);
	freeall(&pushswap);
	return (0);
}
