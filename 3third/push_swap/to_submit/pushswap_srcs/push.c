#include "push_swap.h"

void	pa(t_pushswap *stack)
{
	if (!stack->b_size)
		return ;
	if (stack->print)
		write(1, "pa\n", 3);
	else
		++stack->moves;
	push(stack->stack_b, &stack->b_size, stack->stack_a, &stack->a_size);
}

void	pb(t_pushswap *stack)
{
	if (!stack->a_size)
		return ;
	if (stack->print)
		write(1, "pb\n", 3);
	else
		++stack->moves;
	push(stack->stack_a, &stack->a_size, stack->stack_b, &stack->b_size);
}
