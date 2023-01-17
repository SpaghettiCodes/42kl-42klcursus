/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:20:26 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 16:20:26 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve(t_pushswap *stack)
{
	init_stacks(stack);
	if (stack->total_size < 100)
		stack->print = TRUE;
	if (stack->total_size == 2)
		solve_two(stack);
	else if (stack->total_size == 3)
		solve_three(stack);
	else if (stack->total_size < 100)
		solve_small_big(stack);
	else
		solve_very_big(stack);
}
