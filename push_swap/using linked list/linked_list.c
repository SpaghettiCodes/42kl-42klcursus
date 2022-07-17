#include "pushswap.h"

t_stack	*initialize(char *nbr, t_stack *head)
{
	t_stack *stack;

	stack = (t_stack *) malloc (sizeof(t_stack));
	stack->num = ft_atoi(nbr, head);
	stack->next = NULL;
	return (stack);
}

t_stack	*makestack(int ac, char **av)
{
	int	i;
	t_stack *stack;
	t_stack *current;

	i = 1;
	stack = initialize(av[i], stack);
	current = stack;
	while (++i < (ac - 1))
	{
		current->next = initialize(av[i], stack);
		current = current->next;
	}
	current->next = initialize(av[i], stack);
	return (stack);
}
