#include "push_swap.h"

void	sa(t_pushswap *stack)
{
	if (stack->a_size < 2)
		return ;
	add_node(stack->instructions, "sa\n\0");
	swap(&stack->stack_a[0], &stack->stack_a[1]);
}

void	sb(t_pushswap *stack)
{
	if (stack->b_size < 2)
		return ;
	add_node(stack->instructions, "sb\n\0");
	swap(&stack->stack_b[0], &stack->stack_b[1]);
}

void	ss(t_pushswap *stack)
{
	add_node(stack->instructions, "ss\n\0");
	sa(stack);
	sb(stack);
}

void	pa(t_pushswap *stack)
{
	add_node(stack->instructions, "pa\n\0");
	push(stack->stack_b, &stack->b_size, stack->stack_a, &stack->a_size);
}

void	pb(t_pushswap *stack)
{
	add_node(stack->instructions, "pb\n\0");
	push(stack->stack_a, &stack->a_size, stack->stack_b, &stack->b_size);
}

void	ra(t_pushswap *stack)
{
	add_node(stack->instructions, "ra\n\0");
	if (stack->a_size < 2)
		return ;
	rotate(stack->stack_a, stack->a_size);
}

void	rb(t_pushswap *stack)
{
	add_node(stack->instructions, "rb\n\0");
	if (stack->b_size < 2)
		return ;
	rotate(stack->stack_b, stack->b_size);
}

void	rr(t_pushswap *stack)
{
	add_node(stack->instructions, "rr\n\0");
	ra(stack);
	rb(stack);
}

void	rra(t_pushswap *stack)
{
	add_node(stack->instructions, "rra\n\0");
	if (stack->a_size < 2)
		return ;
	reverserotate(stack->stack_a, stack->a_size);
}

void	rrb(t_pushswap *stack)
{
	add_node(stack->instructions, "rrb\n\0");
	if (stack->b_size < 2)
		return ;
	reverserotate(stack->stack_b, stack->b_size);
}

void	rrr(t_pushswap *stack)
{
	add_node(stack->instructions, "rrr\n\0");
	rra(stack);
	rrb(stack);
}
