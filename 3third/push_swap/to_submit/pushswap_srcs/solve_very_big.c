#include "push_swap.h"

void	push_to_a(t_pushswap *stack, int start, int end)
{
	int	max_val;
	int	min_val;

	max_val = stack->sorted[end];
	min_val = stack->sorted[start];
	init_chunk(stack);
	while (stack->b_size)
	{
		find_lesser_moves(stack, max_val, min_val);
		rotate_to_correct(stack, moves_needed_rot_a(stack, stack->stack_b[0], max_val, min_val) ,'a');
		pa(stack);
	}
}

void	push_to_b(t_pushswap *stack, int start_loc, int end_loc, int chunk_size)
{
	int max;
	int min;

	max = stack->sorted[end_loc];
	min = stack->sorted[start_loc]; 
	while (chunk_size)
	{
		find_and_push(stack, max, min);
		chunk_size--;
	}
}

void	solve_chunk(t_pushswap *stack, int count)
{
	int	chunk_size;
	int	remainder;
	int	start;
	int	end;

	chunk_size = stack->total_size / count;
	remainder = stack->total_size % count;
	while (count > 0)
	{
		end = ((chunk_size * count) - 1);
		start = (end - chunk_size) + 1;
		end = end + remainder;
		push_to_b(stack, start, end, (chunk_size + remainder));
		go_to_last_chunk(stack, end + 1);
		push_to_a(stack, start, end);
		if (remainder)
			remainder = 0;
		count--;
	}
	revert_changes(stack);
}

void	solve_very_big(t_pushswap *stack)
{
	int				count;
	unsigned int	smallest_count;
	unsigned int	smallest_moves;

	count = 1;
	smallest_moves = INT_MAX;
	while (++count <= 5)
	{
		stack->moves = 0;
		init_stacks(stack);
		solve_chunk(stack, count);
		if (stack->moves < smallest_moves)
		{
			smallest_moves = stack->moves;
			smallest_count = count;
		}
	}
	init_stacks(stack);
	stack->print = TRUE;
	solve_chunk(stack, smallest_count);
}
