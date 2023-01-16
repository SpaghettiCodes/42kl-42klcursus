#include "push_swap.h"

void	ra(t_pushswap *stack)
{
	if (stack->a_size < 2)
		return ;
	if (stack->print)
		write(1, "ra\n", 3);
	else
		++stack->moves;
	rotate(stack->stack_a, stack->a_size);
}

void	rb(t_pushswap *stack)
{
	if (stack->b_size < 2)
		return ;
	if (stack->print)
		write(1, "rb\n", 3);
	else
		++stack->moves;
	rotate(stack->stack_b, stack->b_size);
}

void	rr(t_pushswap *stack)
{
	ra(stack);
	rb(stack);
	if (stack->print)
		write(1, "rr\n", 3);
	else
		++stack->moves;
}
