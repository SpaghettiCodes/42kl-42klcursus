#include "pushswap.h"

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
}

void	pb(t_stack **b, t_stack **a)
{
	push(a, b);
}
