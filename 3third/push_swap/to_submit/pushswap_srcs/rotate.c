/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:19:18 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 16:19:19 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_pushswap *stack)
{
	if (stack->a_size < 2)
		return ;
	if (stack->print)
		write(1, "ra\n", 3);
	else
		++stack->moves;
	rotate(stack->stack_a, stack->a_size);
}

void	rb(t_pushswap *stack)
{
	if (stack->b_size < 2)
		return ;
	if (stack->print)
		write(1, "rb\n", 3);
	else
		++stack->moves;
	rotate(stack->stack_b, stack->b_size);
}

void	rr(t_pushswap *stack)
{
	ra(stack);
	rb(stack);
	if (stack->print)
		write(1, "rr\n", 3);
	else
		++stack->moves;
}
