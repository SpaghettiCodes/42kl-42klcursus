#include "checker.h"

void	sa(t_pushswap *stack)
{
	if (stack->a_size < 2)
		return ;
	swap(&stack->stack_a[0], &stack->stack_a[1]);
}

void	sb(t_pushswap *stack)
{
	if (stack->b_size < 2)
		return ;
	swap(&stack->stack_b[0], &stack->stack_b[1]);
}

void	ss(t_pushswap *stack)
{
	sa(stack);
	sb(stack);
}

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

void	ra(t_pushswap *stack)
{
	if (stack->a_size < 2)
		return ;
	rotate(stack->stack_a, stack->a_size);
}

void	rb(t_pushswap *stack)
{
	if (stack->b_size < 2)
		return ;
	rotate(stack->stack_b, stack->b_size);
}

void	rr(t_pushswap *stack)
{
	ra(stack);
	rb(stack);
}

void	rra(t_pushswap *stack)
{
	if (stack->a_size < 2)
		return ;
	reverserotate(stack->stack_a, stack->a_size);
}

void	rrb(t_pushswap *stack)
{
	if (stack->b_size < 2)
		return ;
	reverserotate(stack->stack_b, stack->b_size);
}

void	rrr(t_pushswap *stack)
{
	rra(stack);
	rrb(stack);
}
