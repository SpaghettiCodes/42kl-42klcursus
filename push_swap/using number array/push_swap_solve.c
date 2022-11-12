#include "push_swap.h"

int	solve_two(t_pushswap *stack)
{
	int a;
	int b;

	a = stack->stack_a[0];
	b = stack->stack_a[1];
	if (a > b)
		sa(stack);
	return (2);
}

int	solve_three(t_pushswap *stack)
{
	int a;
	int b;
	int c;

	a = stack->stack_a[0];
	b = stack->stack_a[1];
	c = stack->stack_a[2];
	if (b < c && c < a)
		ra(stack);
	else if ((b < a && c < b))
	{
		sa(stack);
		rra(stack);
	}
	else if (c < a && a < b)
		rra(stack);
	else if (a < c && b < a)
		sa(stack);
	else if (a < c && c < b)
	{
		rra(stack);
		sa(stack);
	}
	return (3);
}

// find the smallest variable location
int smallest_loc(int *stack, int stack_size)
{
    int smallest_val;
    int smallest_loc;
    int i;

    smallest_val = INT_MAX;
    i = -1;
    while (++i < stack_size)
    {
        if (stack[i] < smallest_val && stack[i] < smallest_val)
        {
            smallest_val = stack[i];
            smallest_loc = i;
        }
    }
    return (smallest_loc);
}
