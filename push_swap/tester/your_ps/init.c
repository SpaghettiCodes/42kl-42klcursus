#include "push_swap.h"

int	init_chunk(t_pushswap *stack)
{
	if (stack->stack_b[0] < stack->stack_b[1])
		sb(stack);
	pa(stack);
	pa(stack);
	ra(stack);
	return (0);
}

void	init_stacks(t_pushswap *stack)
{
	if (stack->stack_a)
		free(stack->stack_a);
	if (stack->stack_b)
		free(stack->stack_b);
	stack->stack_a = int_dup(stack->un_sorted, stack->total_size);
	stack->a_size = stack->total_size;
	stack->stack_b = malloc (sizeof(int) * stack->total_size);
	stack->b_size = 0;
}