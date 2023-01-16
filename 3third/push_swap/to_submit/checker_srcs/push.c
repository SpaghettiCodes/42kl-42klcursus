#include "checker.h"

void	pa(t_pushswap *stack)
{
	if (!stack->b_size)
		return ;
	push(stack->stack_b, &stack->b_size, stack->stack_a, &stack->a_size);
}

void	pb(t_pushswap *stack)
{
	if (!stack->a_size)
		return ;
	push(stack->stack_a, &stack->a_size, stack->stack_b, &stack->b_size);
}

