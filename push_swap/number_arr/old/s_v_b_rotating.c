#include "push_swap.h"

void	rotate_to_correct(t_pushswap *stack, int moves, char stack_name)
{
	if (moves > 0)
	{
		while (moves > 0)
		{
			if (stack_name == 'b')
				rb(stack);
			else if (stack_name == 'a')
				ra(stack);
			moves--;
		}
	}
	else if (moves < 0)
	{
		while (moves < 0)
		{
			if (stack_name == 'b')
				rrb(stack);
			else if (stack_name == 'a')
				rra(stack);
			moves++;
		}
	}
}

void	go_to_last_chunk(t_pushswap *stack, int last_stack_smallest_loc)
{
	int	moves;
	int	l_ch_smallest_val;
	int	largest_val_loc;
	int	l_ch_smallest_loc;

	if (last_stack_smallest_loc >= stack->total_size)
		return ;
	l_ch_smallest_val = stack->sorted[last_stack_smallest_loc];
	l_ch_smallest_loc = get_loc(stack, l_ch_smallest_val);
	largest_val_loc = (stack->a_size - get_largest_loc(stack) - 1);
	if (largest_val_loc > l_ch_smallest_loc)
	{	
		if (l_ch_smallest_loc < stack->a_size / 2)
			moves = l_ch_smallest_loc;
		else
			moves = ((stack->a_size - l_ch_smallest_loc) * -1);
	}
	else
	{
		if (largest_val_loc < stack->a_size / 2)
			moves = (largest_val_loc * -1);
		else
			moves = largest_val_loc;
	}
	rotate_to_correct(stack, moves, 'a');
}

void	rot_b(t_pushswap *stack, int smallest_move_loc)
{
	if (smallest_move_loc)
	{
		if (smallest_move_loc < stack->b_size / 2)
			rotate_to_correct(stack, smallest_move_loc, 'b');
		else
			rotate_to_correct(stack, (stack->b_size - smallest_move_loc) * -1, 'b');
	}
}

void	revert_changes(t_pushswap *stack)
{
	int	lowest_loc; 
	int	mid;
	
	mid = stack->a_size / 2;
	lowest_loc = get_lowest_loc(stack);
	if (lowest_loc <= mid)
		rotate_to_correct(stack, lowest_loc, 'a');
	else
		rotate_to_correct(stack, ((stack->a_size - lowest_loc) * -1), 'a');
}
