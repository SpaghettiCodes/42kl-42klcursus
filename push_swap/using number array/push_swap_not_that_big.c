#include "push_swap.h"

void shift_to_correct(t_pushswap *stack, int larger, int toplace)
{
	if (larger)
	{
		while(toplace)
		{
			rra(stack);
			toplace--;
		}
	}
	else
	{
		while(toplace)
		{
			ra(stack);
			toplace--;
		}
	}
}

// pushes the number from b to a based on the number of moves provided (toplace)
void action(t_pushswap *stack, int toplace)
{
	int mid;
	int larger;
	
	mid = stack->a_size / 2;
	larger = toplace > mid;
	// larger = if the placing value is towards the right
	if (larger)
	{
		// push the larger one to the front, then add the new one
		toplace = stack->a_size - toplace;
	}
	shift_to_correct(stack, larger, toplace);
	pa(stack);
}

// find how many variables is the value larger than
int larger_than(int *stack, int reference, int stack_size)
{
    int	larger;
    int	i;

    larger = 0;
    i = -1;
    while(++i < stack_size)
		if (reference > stack[i])
			larger++;
    return (larger);
}

// determine where should we put the variable (how many steps taken)
int moves(int larger_than, int smallest_loc, int stack_size)
{
	// btw, this algo only work if stack A is already sorted
    int	suppose_loc;

	// supposed location = smallest variable location + how many variables larger
    suppose_loc = smallest_loc + larger_than;

	// offset if the location is larger than the size (due to rotating the stack)
	// example = 5 1 2, ref = 3
	// 1 is smallest (smallest loc = 1), larger by 2
	// suppose_loc = 1 + 2 = 3, [5, 1, 2, __]
	// however, we cant use pushswap to put it at the end
	// so real_loc = found_loc - stack_size = 3 - 3 <-- (think of this like a single rotation ) = 0
	// [__, 5, 1, 2]
	// then we can rotate to put it at the back [5, 1, 2, __]
	
	while (suppose_loc >= (stack_size))
        suppose_loc = suppose_loc - stack_size;
    return (suppose_loc);
}

// this is probably the faster way to push B to A

void	search_and_add(t_pushswap *stack)
{
	int	to_place;
	int smlest_val_loc;

	smlest_val_loc = smallest_loc(stack->stack_a, stack->a_size);
	to_place = moves(larger_than(stack->stack_a, stack->stack_b[0], stack->a_size), smlest_val_loc, stack->a_size);
	action(stack, to_place);
}

// as the name suggest, this algo works good for 4 <= x < 100, but terribly for anything above that
void	solve_small_big(t_pushswap *stack)
{
	int smlest_val_loc;
	int larger;

	while(stack->a_size > 3)
		pb(stack);
	solve_three(stack);
	while(stack->b_size > 0)
		search_and_add(stack);

	smlest_val_loc = smallest_loc(stack->stack_a, stack->a_size);
	// if the smallest value location is at the right side of the stack
	larger = smlest_val_loc >= (stack->a_size / 2);
	if (larger)
		// then instead of shifting first to last, shift last to first (faster)
		smlest_val_loc = stack->a_size - smlest_val_loc;
	shift_to_correct(stack, larger, smlest_val_loc);
}
