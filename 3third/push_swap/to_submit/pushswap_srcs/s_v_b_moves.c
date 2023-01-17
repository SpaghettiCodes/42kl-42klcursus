/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_v_b_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:20:19 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 16:20:19 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves_needed_rot_a(t_pushswap *stack, int reference, int max, int min)
{
	int	first_elem_loc;
	int	no_smallerthan_ref;
	int	no_biggerthan_ref;
	int	last_elem_loc;

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
		return ((no_biggerthan_ref) * -1);
	else
		return (no_smallerthan_ref);
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
		rot_a_moves = moves_needed_rot_a(stack, stack->stack_b[i],
				max_val, min_val);
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

int	find_and_push(t_pushswap *stack, int max, int min)
{
	int	moves;
	int	closest_start;
	int	closest_end;

	closest_start = -1;
	while (++closest_start < stack->a_size)
		if (stack->stack_a[closest_start] >= min
			&& stack->stack_a[closest_start] <= max)
			break ;
	closest_end = stack->a_size;
	while (--closest_end >= 0)
		if (stack->stack_a[closest_end] >= min
			&& stack->stack_a[closest_end] <= max)
			break ;
	closest_end = (stack->a_size - closest_end);
	if (closest_start == stack->a_size && closest_end == -1)
		return (0);
	if (closest_start < (closest_end))
		moves = closest_start;
	else
		moves = ((closest_end) * -1);
	rotate_to_correct(stack, moves, 'a');
	pb(stack);
	return (1);
}
