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
	write(1, "ra\n", 3);
	rotate(a);
}

void	rb(t_stack **b)
{
	write(1, "rb\n", 3);
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	write(1, "rr\n", 3);
	rra(a);
	rrb(b);
}

void	rra(t_stack **a)
{
	write(1, "rra\n", 4);
	reverserotate(a);
}

void	rrb(t_stack **b)
{
	write(1, "rrb\n", 4);
	reverserotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	write(1, "rrr\n", 4);
	rra(a);
	rrb(b);
}

