/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:19:15 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 16:19:15 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_pushswap *stack)
{
	if (stack->a_size < 2)
		return ;
	if (stack->print)
		write(1, "rra\n", 4);
	else
		++stack->moves;
	reverserotate(stack->stack_a, stack->a_size);
}

void	rrb(t_pushswap *stack)
{
	if (stack->b_size < 2)
		return ;
	if (stack->print)
		write(1, "rrb\n", 4);
	else
		++stack->moves;
	reverserotate(stack->stack_b, stack->b_size);
}

void	rrr(t_pushswap *stack)
{
	rra(stack);
	rrb(stack);
	if (stack->print)
		write(1, "rrr\n", 4);
	else
		++stack->moves;
}
