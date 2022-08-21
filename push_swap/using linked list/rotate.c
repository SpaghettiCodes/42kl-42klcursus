#include "pushswap.h"

void	reverserotate(t_stack **tab)
{
	shift_right(tab);
}

void	rotate(t_stack **tab)
{
	shift_left(tab);
}

void	ra(t_stack **a)
{
	rotate(a);
}

void	rb(t_stack **b)
{
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}

void	rra(t_stack **a)
{
	reverserotate(a);
}

void	rrb(t_stack **b)
{
	reverserotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}

