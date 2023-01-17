/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_n_t_b_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:31:58 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 17:32:47 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// find how many variables is the value larger than
int	larger_than(int *stack, int reference, int stack_size)
{
	int	larger;
	int	i;

	larger = 0;
	i = -1;
	while (++i < stack_size)
		if (reference > stack[i])
			larger++;
	return (larger);
}

// determine where should we put the variable (how many steps taken)

// supposed location = smallest variable location + how many variables larger
// offset if the location calculated is larger than the size
// example = 5 1 2, ref = 3
// 1 is smallest (smallest loc = 1), larger by 2
// suppose_loc = 1 + 2 = 3 ==> [5, 1, 2, __]
// however, we cant use push to put it at the end
// so real_loc = found_loc - stack_size = 3 - 3 <-- (single rotation) = 0
// [__, 5, 1, 2]
// then we can rotate to put it at the back [5, 1, 2, __]
int	moves(int larger_than, int smallest_loc, int stack_size)
{
	int	suppose_loc;

	suppose_loc = smallest_loc + larger_than;
	while (suppose_loc >= (stack_size))
		suppose_loc = suppose_loc - stack_size;
	return (suppose_loc);
}

void	search_and_add(t_pushswap *stack)
{
	int	to_place;
	int	smlest_val_loc;

	smlest_val_loc = get_lowest_loc(stack);
	to_place = moves(larger_than(stack->stack_a, stack->stack_b[0],
				stack->a_size), smlest_val_loc, stack->a_size);
	action(stack, to_place);
}
