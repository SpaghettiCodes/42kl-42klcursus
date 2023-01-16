#include "push_swap.h"

void	sa(t_pushswap *stack)
{
	if (stack->a_size < 2)
		return ;
	printf("sa\n");
	swap(&stack->stack_a[0], &stack->stack_a[1]);
}

void	sb(t_pushswap *stack)
{
	if (stack->b_size < 2)
		return ;
	printf("sb\n");
	swap(&stack->stack_b[0], &stack->stack_b[1]);
}

void	ss(t_pushswap *stack)
{
	printf("ss\n");
	sa(stack);
	sb(stack);
}

void	pa(t_pushswap *stack)
{
	printf("pa\n");
	push(stack->stack_b, &stack->b_size, stack->stack_a, &stack->a_size);
}

void	pb(t_pushswap *stack)
{
	printf("pb\n");
	push(stack->stack_a, &stack->a_size, stack->stack_b, &stack->b_size);
}

void	ra(t_pushswap *stack)
{
	printf("ra\n");
	if (stack->a_size < 2)
		return ;
	rotate(stack->stack_a, stack->a_size);
}

void	rb(t_pushswap *stack)
{
	printf("rb\n");
	if (stack->b_size < 2)
		return ;
	rotate(stack->stack_b, stack->b_size);
}

void	rr(t_pushswap *stack)
{
	printf("rr\n");
	ra(stack);
	rb(stack);
}

void	rra(t_pushswap *stack)
{
	printf("rra\n");
	if (stack->a_size < 2)
		return ;
	reverserotate(stack->stack_a, stack->a_size);
}

void	rrb(t_pushswap *stack)
{
	printf("rrb\n");
	if (stack->b_size < 2)
		return ;
	reverserotate(stack->stack_b, stack->b_size);
}

void	rrr(t_pushswap *stack)
{
	printf("rrr\n");
	rra(stack);
	rrb(stack);
}
