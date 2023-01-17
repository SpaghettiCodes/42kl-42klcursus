/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_not_that_big.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:20:21 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 16:20:21 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_to_correct(t_pushswap *stack, int larger, int toplace)
{
	if (larger)
	{
		while (toplace)
		{
			rra(stack);
			toplace--;
		}
	}
	else
	{
		while (toplace)
		{
			ra(stack);
			toplace--;
		}
	}
}

// pushes the number from b to a based on the number of moves provided (toplace)
void	action(t_pushswap *stack, int toplace)
{
	int	mid;
	int	larger;

	mid = stack->a_size / 2;
	larger = toplace > mid;
	if (larger)
		toplace = stack->a_size - toplace;
	shift_to_correct(stack, larger, toplace);
	pa(stack);
}

// if the smallest value location is at the right side of the stack
// then instead of shifting first to last, shift last to first (faster)
void	solve_small_big(t_pushswap *stack)
{
	int	smlest_val_loc;
	int	larger;

	while (stack->a_size > 3)
		pb(stack);
	solve_three(stack);
	while (stack->b_size > 0)
		search_and_add(stack);
	smlest_val_loc = get_lowest_loc(stack);
	larger = smlest_val_loc >= (stack->a_size / 2);
	if (larger)
		smlest_val_loc = stack->a_size - smlest_val_loc;
	shift_to_correct(stack, larger, smlest_val_loc);
}
