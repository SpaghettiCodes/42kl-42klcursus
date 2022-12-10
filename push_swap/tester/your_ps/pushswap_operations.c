#include "push_swap.h"

void	sa(t_pushswap *stack)
{
	if (stack->a_size < 2)
		return ;
	if (stack->print)
		write(1, "sa\n", 3);
	else
		stack->moves++;
	swap(&stack->stack_a[0], &stack->stack_a[1]);
}

void	sb(t_pushswap *stack)
{
	if (stack->b_size < 2)
		return ;
	if (stack->print)
		write(1, "sb\n", 3);
	else
		stack->moves++;
	swap(&stack->stack_b[0], &stack->stack_b[1]);
}

void	ss(t_pushswap *stack)
{
	if (stack->print)
		write(1, "ss\n", 3);
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
		write(1, "pa\n", 3);
	else
		stack->moves++;
	push(stack->stack_b, &stack->b_size, stack->stack_a, &stack->a_size);
}

void	pb(t_pushswap *stack)
{
	if (!stack->a_size)
		return ;
	if (stack->print)
		write(1, "pb\n", 3);
	else
		stack->moves++;
	push(stack->stack_a, &stack->a_size, stack->stack_b, &stack->b_size);
}

void	ra(t_pushswap *stack)
{
	if (stack->a_size < 2)
		return ;
	if (stack->print)
		write(1, "ra\n", 3);
	else
		stack->moves++;
	rotate(stack->stack_a, stack->a_size);
}

void	rb(t_pushswap *stack)
{
	if (stack->b_size < 2)
		return ;
	if (stack->print)
		write(1, "rb\n", 3);
	else
		stack->moves++;
	rotate(stack->stack_b, stack->b_size);
}

void	rr(t_pushswap *stack)
{
	ra(stack);
	rb(stack);
	if (stack->print)
		write(1, "rr\n", 3);
	else
		stack->moves++;
}

void	rra(t_pushswap *stack)
{
	if (stack->a_size < 2)
		return ;
	if (stack->print)
		write(1, "rra\n", 4);
	else
		stack->moves++;
	reverserotate(stack->stack_a, stack->a_size);
}

void	rrb(t_pushswap *stack)
{
	if (stack->b_size < 2)
		return ;
	if (stack->print)
		write(1, "rrb\n", 4);
	else
		stack->moves++;
	reverserotate(stack->stack_b, stack->b_size);
}

void	rrr(t_pushswap *stack)
{
	rra(stack);
	rrb(stack);
	if (stack->print)
		write(1, "rrr\n", 4);
	else
		stack->moves++;
}
