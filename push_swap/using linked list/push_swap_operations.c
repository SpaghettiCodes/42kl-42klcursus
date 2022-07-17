#include "pushswap.h"

void	sa(t_stack *a)
{
	swap(&a);
}

void	sb(t_stack *b)
{
	swap(&b);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	push(&b, &a);
}

void	pb(t_stack *b, t_stack *a)
{
	push(&a, &b);
}

void	ra(t_stack *a)
{
	rotate(a);
}

void	rb(t_stack *b)
{
	rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}

void	rra(t_stack *a)
{
	reverserotate(a);
}

void	rrb(t_stack *b)
{
	reverserotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
