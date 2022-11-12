// oh boy
// oh boy
// 100 <= x <= 700 numbers time wahooooooooooo
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

int	largest_val_loc(t_pushswap *stack)
{
	int	i;
	int largest;

	i = -1;
	largest = 0;
	while (++i < stack->a_size)
	{
		if (stack->stack_a[largest] < stack->stack_a[i])
			largest = i;
	}
	return (largest + 1);
}


int	smallerby(t_pushswap *stack, int reference, int last_elem_loc)
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

int	largerby(t_pushswap *stack, int reference, int first_elem_loc)
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

int	initialization(t_pushswap *stack)
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

int	moves_needed(t_pushswap *stack, int max, int min)
{
	int first_elem_loc;
	int biggerthan;
	int smallerthan;
	int last_elem_loc;
	int reference;
	int	moves;

	last_elem_loc = find_end_half(stack, max, min);

	if (last_elem_loc == stack->a_size)
	{
		ra(stack);
		last_elem_loc = stack->a_size - 1;
	}

	first_elem_loc = find_start_half(stack, max, min);

	reference = stack->stack_b[0];

	biggerthan = largerby(stack, reference, first_elem_loc);
	smallerthan = smallerby(stack, reference, last_elem_loc);
	if (biggerthan < (smallerthan + 1) && (smallerthan))
		moves = (smallerthan) * -1;
	else
		moves = biggerthan;

	return (moves);
}

void	push_to_a(t_pushswap *stack, int start, int end)
{
	int	max_val;
	int	min_val;

	max_val = stack->sorted[end];
	min_val = stack->sorted[start];
	initialization(stack);
	while (stack->b_size)
	{
		rotate_to_correct(stack, moves_needed(stack, max_val, min_val) ,'a');
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

	if (closest_start == stack->a_size && closest_end == -1)
		return(0);

	if (closest_start < (closest_end + 1))
		moves = closest_start;
	else
		moves = ((closest_end + 1) * -1);
	
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

int	is_solved(t_pushswap *stack)
{
	int	i;

	i = -1;
	while (++i < (stack->a_size - 1))
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
			return 0;
	}
	return 1;
}

void	solve_chunk(t_pushswap *stack, int count)
{
	int chunk_size;
	int remainder_used;
	int	remainder;
	int start;
	int end;

	chunk_size = stack->total_size / count;
	remainder = stack->total_size % count;
	remainder_used = remainder;
	while (count > 0)
	{
		// wtf??
		end = (chunk_size * count) - 1;
		start = (end - chunk_size) + 1;
		// future me FIX THIS
		if (remainder_used)
		{
			end = end + remainder;
			push_to_b(stack, start, end, (chunk_size + remainder));
			push_to_a(stack, start, end);
			remainder_used = 0;
		}
		else
		{
			push_to_b(stack, start, end, chunk_size);
			push_to_a(stack, start, end);
		}
		count--;
	}
	revert_changes(stack);
}

// ok i dont know what is divide and conqure ipraytogodiknowwhatiamdoing
// you know i never know why divide and conqure is faster than linear alogrithm
// ehe
void	divide_and_conqure(t_pushswap *stack)
{
	if (stack->total_size >= 100 && stack->total_size <= 400)
	{
		//seperate into 4 chunks
		solve_chunk(stack, 4);
	}
	else
	{
		//seperate into 15 chunks
		solve_chunk(stack, 15);
	}
}

void	solve_very_big(t_pushswap *stack)
{
	divide_and_conqure(stack);
}
