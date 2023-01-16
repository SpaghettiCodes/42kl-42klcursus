#include "push_swap.h"

// a better algo to push to b

// rotate
int rontate_get_small(t_pushswap *stacks, int moves)
{
    if (moves > 0)
    {
        while (moves > 0)
        {
            ra(stacks);
            moves--;
        }
    }
    else if (moves < 0)
    {
        while (moves < 0)
        {
            rra(stacks);
            moves++;
        }
    }
}

// heads up - i do not think this works
void	optimizer(t_pushswap *stacks)
{
	// swap if 1st value < 2nd value
	if (stacks->b_size > 1)
	{
		if(stacks->stack_b[0] < stacks->stack_b[1])
			sb(stacks);
		if(stacks->stack_b[stacks->b_size - 1] > stacks->stack_b[0])
			rrb(stacks);
	}
}

int choose_closer(t_pushswap *stacks, int midpoint_val, int iter)
{
    int closest_start;
    int closest_end;
    int moves;
    
    // figure out the 1st variable larger than the midpoint location closest to the start
    closest_start = 0;
    while (closest_start < stacks->a_size && midpoint_val < stacks->stack_a[closest_start])
    {
        closest_start++;
    }
    // figure out the 1st variable larger than the location closest to the end
    closest_end = stacks->a_size - 1;
    while (closest_end >= 0 && midpoint_val < stacks->stack_a[closest_end])
    {
        closest_end--;
    }

    //check if there is no largest variable
    if (closest_start == (stacks->a_size) && closest_end == -1)
        return 0;

    // count from back
    closest_end = stacks->a_size - closest_end;
    
    // compare moves needed to be taken
    if (closest_end < closest_start)
        moves = closest_end * -1;
    else
        moves = closest_start;

    // rotate
    rontate_get_small(stacks, moves);
    
    // push
    pb(stacks);

	if (iter == 1)
		optimizer(stacks);
}

int better_pb(t_pushswap *stacks)
{
    int midpoint_val;
    int midpoint_loc;
	int iter;

	iter = 0;
    midpoint_loc = stacks->total_size;
    while (stacks->a_size > 3)
    {   
        // get optimal midpoint (maaybe i should NOT have done this)
        midpoint_loc = midpoint_loc / 2;
        midpoint_val = stacks->sorted[midpoint_loc];
		iter++;

        // push all the numbers smaller than midpoint
        while (choose_closer(stacks, midpoint_val, iter)){};
    }
}