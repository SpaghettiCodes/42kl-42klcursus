// oh boy
// oh boy
// 100 <= x <= 700 numbers time wahooooooooooo
// documentation on this is going to be ass
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

int	get_no_larger(t_pushswap *stack, int reference, int last_elem_loc)
{
	int location;

	location = stack->a_size;
	while (--location >= last_elem_loc)
	{
		if (stack->stack_a[location] < reference)
			break;
	}
	location = (stack->a_size - location - 1);

	return (location);
}

int	get_no_smaller(t_pushswap *stack, int reference, int first_elem_loc)
{
	int	location;

	location = -1;
	while (++location <= first_elem_loc)
	{
		if (stack->stack_a[location] > reference)
			break;
	}
	return (location);
}

int	init_chunk(t_pushswap *stack)
{
	if (stack->stack_b[0] < stack->stack_b[1])
		sb(stack);
	pa(stack);
	pa(stack);
	ra(stack);
	return (0);
}

int	find_start_half(t_pushswap *stack, int max, int min)
{
	int	closest_start;

	closest_start = -1;
	while (++closest_start < stack->a_size)
		if ((stack->stack_a[closest_start] < min || stack->stack_a[closest_start] > max))
			break;

	return (closest_start - 1);
}

int	find_end_half(t_pushswap *stack, int max, int min)
{
	int	closest_end;

	closest_end = stack->a_size;
	while (--closest_end >= 0)
		if ((stack->stack_a[closest_end] < min || stack->stack_a[closest_end] > max))
			break;

	return (closest_end + 1);
}

int	moves_needed_rot_a(t_pushswap *stack, int reference, int max, int min)
{
	int first_elem_loc;
	int no_smallerthan_ref;
	int no_biggerthan_ref;
	int last_elem_loc;

	last_elem_loc = find_end_half(stack, max, min);
	if (last_elem_loc == stack->a_size)
	{
		ra(stack);
		last_elem_loc = stack->a_size - 1;
	}
	first_elem_loc = find_start_half(stack, max, min);

	no_smallerthan_ref = get_no_smaller(stack, reference, first_elem_loc);
	no_biggerthan_ref = get_no_larger(stack, reference, last_elem_loc);
	if (no_biggerthan_ref)
		return((no_biggerthan_ref) * -1);
	else
		return(no_smallerthan_ref);
}

int	get_loc(t_pushswap *stack, int val)
{
	int i;

	i = -1;
	while (++i < stack->a_size)
		if (stack->stack_a[i] == val)
			break;
	return (i);
}

int	get_largest_loc(t_pushswap *stack)
{
	int	i;
	int	largest;

	i = -1;
	largest = 0;
	while (++i < stack->a_size)
		if (stack->stack_a[i] > stack->stack_a[largest])
			largest = i;
	return (largest);
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

void	find_lesser_moves(t_pushswap *stack, int max_val, int min_val)
{
	int	i;
	int	smallest_move;
	int	smallest_move_loc;
	int	rot_a_moves;
	int	rot_b_moves;

	smallest_move = INT_MAX;
	i = -1;
	while (++i < stack->b_size)
	{
		rot_a_moves = moves_needed_rot_a(stack, stack->stack_b[i], max_val, min_val);
		if (rot_a_moves < 0)
			rot_a_moves = rot_a_moves * -1;
		rot_b_moves = i;
		if (i > stack->b_size / 2)
			rot_b_moves = stack->b_size - rot_b_moves;
		if (rot_b_moves + rot_a_moves < smallest_move)
		{
			smallest_move_loc = i;
			smallest_move = rot_b_moves + rot_a_moves;
		}
	}
	rot_b(stack, smallest_move_loc);
}

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

int	find_and_push(t_pushswap *stack, int max, int min)
{
	int moves;
	int	closest_start;
	int	closest_end;

	closest_start = -1;
	while (++closest_start < stack->a_size)
		if (stack->stack_a[closest_start] >= min && stack->stack_a[closest_start] <= max)
			break;

	closest_end = stack->a_size;
	while (--closest_end >= 0)
		if (stack->stack_a[closest_end] >= min && stack->stack_a[closest_end] <= max)
			break;
	closest_end = (stack->a_size - closest_end);

	if (closest_start == stack->a_size && closest_end == -1)
		return(0);

	if (closest_start < (closest_end))
		moves = closest_start;
	else
		moves = ((closest_end) * -1);
	
	rotate_to_correct(stack, moves, 'a');
	pb(stack);
	return(1);
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

int	get_lowest_loc(t_pushswap *stack)
{
	int i;
	int location;

	i = -1;
	location = 0;
	while (++i < stack->a_size)
	{
		if (stack->stack_a[location] > stack->stack_a[i])
			location = i;
	}
	return (location);
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

void	solve_chunk(t_pushswap *stack, int count)
{
	int chunk_size;
	int	remainder;
	int start;
	int end;

	chunk_size = stack->total_size / count;
	remainder = stack->total_size % count;
	while (count > 0)
	{
		end = (chunk_size * count) - 1;
		start = (end - chunk_size) + 1;
		if (remainder)
		{
			end = end + remainder;
			push_to_b(stack, start, end, (chunk_size + remainder));
			push_to_a(stack, start, end);
			remainder = 0;
		}
		else
		{
			push_to_b(stack, start, end, chunk_size);
			go_to_last_chunk(stack, end + 1);
			push_to_a(stack, start, end);
		}
		count--;
	}
	revert_changes(stack);
}

// ok i dont know what is divide and conqure ipraytogodiknowwhatiamdoing
// you know i never know why divide and conqure is faster than linear alogrithm
// ehe

int	*copy(int *source, int source_size)
{
	int	i;
	int	*ret;

	i = -1;
	ret = malloc(sizeof(int) * source_size);
	while (++i < source_size)
		ret[i] = source[i];
	return (ret);
}

void	solve_very_big(t_pushswap *stack)
{
	int	count;
	int	smallest_count;
	int smallest_steps;
	int	moves;

	count = 1;
	smallest_steps = INT_MAX;
	while (++count <= 5)
	{
		init_stacks(stack);
		solve_chunk(stack, count);
		moves = count_instruct(stack->instructions);
		if (moves < smallest_steps)
		{
			smallest_steps = moves;
			smallest_count = count;
		}
	}
	init_stacks(stack);
	solve_chunk(stack, smallest_count);
}
