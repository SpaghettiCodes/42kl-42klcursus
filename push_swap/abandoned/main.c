#include <unistd.h>
#include <stdlib.h>
#include "pushswap.h"

int	*int_dup(int ac, char **av)
{
	int	*list;
	int	i;
	int	j;

	list = malloc((ac-1) * sizeof(int));
	i = -1;
	j = 1;

	while (++i < (ac-1))
	{
		printf("%d", i);
		list[i] = atoi(av[j]);
		j++;
	}
	q_sort(list, 0, (ac-1)-1);
	return (list);
}

int	checkdupli(int *list, int total_num)
{
	int	i;

	i = 0;
	while (++i < total_num)
	{
		if (list[i-1] == list[i])
			return (0);
	}
	return (1);
}

int	pushswapsolve(t_stack **stacka, t_stack **stackb, int *sorted_list, int total_num)
{
	if (total_num == 2)
		return (solve_two(stacka));
	else if (total_num == 3)
		return (solve_three(stacka));
	else
		return (solve_more(stacka, stackb));
}

// testing
#include <stdio.h>

int	printstack(t_stack *stacka)
{
	t_stack *current;
	current = stacka;

	while (current)
	{
		printf("%d ", current->num);
		current = current->next;
	}
	printf("\n");

	return (3);
}

int	main(int ac, char **av)
{
	t_stack*	stacka;
	t_stack*	stackb;
	int*		sorted_list;
	int			total_num;

	if (ac < 2)
		return (error(NULL, NULL, NULL));
	total_num = (ac - 1);
	sorted_list = int_dup(ac, av);
	if (!checkdupli(sorted_list, total_num))
	{
		error(NULL, NULL, sorted_list);
		return (0);
	}
	stacka = makestack(ac, av);
	stackb = NULL;

	printf("total number of element = %d\n", total_num);
	printstack(stacka);
	printf("\n");

	pushswapsolve(&stacka, &stackb, sorted_list, total_num);

	printstack(stacka);

	freeall(stacka, stackb, sorted_list);
	return (2);
}

