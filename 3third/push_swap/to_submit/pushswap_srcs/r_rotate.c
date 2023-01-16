#include "push_swap.h"

void	rra(t_pushswap *stack)
{
	if (stack->a_size < 2)
		return ;
	if (stack->print)
		write(1, "rra\n", 4);
	else
		++stack->moves;
	reverserotate(stack->stack_a, stack->a_size);
}

void	rrb(t_pushswap *stack)
{
	if (stack->b_size < 2)
		return ;
	if (stack->print)
		write(1, "rrb\n", 4);
	else
		++stack->moves;
	reverserotate(stack->stack_b, stack->b_size);
}

void	rrr(t_pushswap *stack)
{
	rra(stack);
	rrb(stack);
	if (stack->print)
		write(1, "rrr\n", 4);
	else
		++stack->moves;
}
