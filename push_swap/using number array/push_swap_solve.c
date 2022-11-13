#include "push_swap.h"

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

void solve(t_pushswap *stack)
{
	if (stack->a_size == 2)
		solve_two(stack);
	else if (stack->a_size == 3)
		solve_three(stack);
	else if (stack->a_size < 100)
		solve_small_big(stack);
	else 
		solve_very_big(stack);
}
