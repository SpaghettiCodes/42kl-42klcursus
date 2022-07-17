#include "push_swap.h"

void	sa(int *a, int size_a)
{
	if (size_a < 2)
		return ;
	swap(&a[0], &a[1]);
}

void	sb(int *b, int size_b)
{
	if (size_b < 2)
		return ;
	swap(&b[0], &b[1]);
}

void	ss(int *a, int size_a, int *b, int size_b)
{
	sa(a, size_a);
	sb(b, size_b);
}

void	pa(int *a, int *size_a, int *b, int *size_b)
{
	push(b, size_b, a, size_a);
}

void	pb(int *b, int *size_b, int *a, int *size_a)
{
	push(a, size_a, b, size_b);
}

void	ra(int *a, int size_a)
{
	if (size_a < 2)
		return ;
	rotate(a, size_a);
}

void	rb(int *b, int size_b)
{
	if (size_b < 2)
		return ;
	rotate(b, size_b);
}

void	rr(int *a, int size_a, int *b, int size_b)
{
	rra(a, size_a);
	rrb(b, size_b);
}

void	rra(int *a, int size_a)
{
	if (size_a < 2)
		return ;
	reverserotate(a, size_a);
}

void	rrb(int *b, int size_b)
{
	if (size_b < 2)
		return ;
	reverserotate(b, size_b);
}

void	rrr(int *a, int size_a, int *b, int size_b)
{
	rra(a, size_a);
	rrb(b, size_b);
}
