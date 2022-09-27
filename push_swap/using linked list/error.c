#include "pushswap.h"

int	freeall(t_stack *stacka, t_stack *stackb, int *sorted_list)
{
	if (sorted_list)
		free(sorted_list);
	printf("freed list\n");
	if (stacka)
		delstack(stacka);
	printf("freed stack a\n");
	if (stackb)
		delstack(stackb);
	printf("freed stack b\n");
}

int	error(t_stack *stacka, t_stack *stackb, int *sorted_list)
{
	write(1, "Error\n", 7);
	freeall(stacka, stackb, sorted_list);
	exit(69);
	return (420);
}

void	delstack(t_stack *stack)
{
	t_stack *current;
	t_stack *temp;
	current = stack;

	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}
