#include "push_swap.h"

int	error(t_pushswap *stack)
{
	if (stack)
	{
		if (stack->stack_a)
			free(stack->stack_a);
		if (stack->stack_b)
			free(stack->stack_b);
	}
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
		stack->stack_a[i] = ft_atoi(av[++j], stack);
	return (1);
}

int	checkdup(t_pushswap *stack)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stack->a_size)
	{
		j = i;
		while (++j < stack->a_size)
		{
			if (stack->stack_a[i] == stack->stack_a[j])
			{
				printf("found error\n");
				return (error(stack));
			}
		}
	}
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

int	is_solved(t_pushswap *stack)
{
	int	i;

	i = -1;
	while (++i < (stack->a_size - 1))
		if (stack->stack_a[i] > stack->stack_a[i+1])
			return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_pushswap pushswap; 

	if (ac <= 1)
		return (error(NULL));
	pushswap.stack_a = (int *) malloc ((ac - 1) * sizeof(int));
	pushswap.total_size = ac - 1;
	pushswap.a_size = ac - 1;
	pushswap.stack_b = (int *) malloc ((ac - 1) * sizeof(int));
	ft_bzero(pushswap.stack_b, ac - 1);
	pushswap.b_size = 0;
	fill(&pushswap, av, ac);
	checkdup(&pushswap);

	pushswap.sorted = int_dup(pushswap.stack_a, pushswap.a_size);

	if (!is_solved(&pushswap))
		solve(&pushswap); // this would be the sorting algo
	printstack(&pushswap);

	if (pushswap.stack_a)
		free(pushswap.stack_a);
	if (pushswap.stack_b)
		free(pushswap.stack_b);
	if (pushswap.sorted)
		free(pushswap.sorted);

	return (1);
}
