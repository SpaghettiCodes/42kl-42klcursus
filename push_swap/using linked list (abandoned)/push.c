#include "pushswap.h"

void	pa(t_stack **a, t_stack **b)
{
	write(1, "pa\n", 3);
	push(b, a);
}

void	pb(t_stack **b, t_stack **a)
{
	write(1, "pb\n", 3);
	push(a, b);
}
