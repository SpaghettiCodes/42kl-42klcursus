#include "push_swap.h"

void	sa(t_pushswap *stack)
{
	if (stack->a_size < 2)
		return ;
	if (stack->print)
		printf("sa\n");
	else
		stack->moves++;
	swap(&stack->stack_a[0], &stack->stack_a[1]);
}

void	sb(t_pushswap *stack)
{
	if (stack->b_size < 2)
		return ;
	if (stack->print)
		printf("sb\n");
	else
		stack->moves++;
	swap(&stack->stack_b[0], &stack->stack_b[1]);
}

void	ss(t_pushswap *stack)
{
	if (stack->print)
		printf("ss\n");
	else
		stack->moves++;
	sa(stack);
	sb(stack);
}

void	pa(t_pushswap *stack)
{
	if (!stack->b_size)
		return ;
	if (stack->print)
		printf("pa\n");
	else
		stack->moves++;
	push(stack->stack_b, &stack->b_size, stack->stack_a, &stack->a_size);
}

void	pb(t_pushswap *stack)
{
	if (!stack->a_size)
		return ;
	if (stack->print)
		printf("pb\n");
	else
		stack->moves++;
	push(stack->stack_a, &stack->a_size, stack->stack_b, &stack->b_size);
}

void	ra(t_pushswap *stack)
{
	if (stack->a_size < 2)
		return ;
	if (stack->print)
		printf("ra\n");
	else
		stack->moves++;
	rotate(stack->stack_a, stack->a_size);
}

void	rb(t_pushswap *stack)
{
	if (stack->b_size < 2)
		return ;
	if (stack->print)
		printf("rb\n");
	else
		stack->moves++;
	rotate(stack->stack_b, stack->b_size);
}

void	rr(t_pushswap *stack)
{
	ra(stack);
	rb(stack);
	if (stack->print)
		printf("rr\n");
	else
		stack->moves++;
}

void	rra(t_pushswap *stack)
{
	if (stack->a_size < 2)
		return ;
	if (stack->print)
		printf("rra\n");
	else
		stack->moves++;
	reverserotate(stack->stack_a, stack->a_size);
}

void	rrb(t_pushswap *stack)
{
	if (stack->b_size < 2)
		return ;
	if (stack->print)
		printf("rrb\n");
	else
		stack->moves++;
	reverserotate(stack->stack_b, stack->b_size);
}

void	rrr(t_pushswap *stack)
{
	rra(stack);
	rrb(stack);
	if (stack->print)
		printf("rrr\n");
	else
		stack->moves++;
}
