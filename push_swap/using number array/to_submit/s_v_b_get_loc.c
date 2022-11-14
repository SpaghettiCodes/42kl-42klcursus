#include "push_swap.h"

int	get_lowest_loc(t_pushswap *stack)
{
	int i;
	int location;

	i = -1;
	location = 0;
	while (++i < stack->a_size)
		if (stack->stack_a[location] > stack->stack_a[i])
			location = i;
	return (location);
}

int	get_largest_loc(t_pushswap *stack)
{
	int	i;
	int	largest;

	i = -1;
	largest = 0;
	while (++i < stack->a_size)
		if (stack->stack_a[i] > stack->stack_a[largest])
			largest = i;
	return (largest);
}

int	get_loc(t_pushswap *stack, int val)
{
	int	i;

	i = -1;
	while (++i < stack->a_size)
		if (stack->stack_a[i] == val)
			break;
	return (i);
}

int	find_start_half(t_pushswap *stack, int max, int min)
{
	int	closest_start;

	closest_start = -1;
	while (++closest_start < stack->a_size)
		if ((stack->stack_a[closest_start] < min || stack->stack_a[closest_start] > max))
			break;

	return (closest_start - 1);
}

int	find_end_half(t_pushswap *stack, int max, int min)
{
	int	closest_end;

	closest_end = stack->a_size;
	while (--closest_end >= 0)
		if ((stack->stack_a[closest_end] < min || stack->stack_a[closest_end] > max))
			break;

	return (closest_end + 1);
}