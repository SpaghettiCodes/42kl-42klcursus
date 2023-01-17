/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:19:09 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 16:19:10 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_pushswap *stack)
{
	if (!stack->b_size)
		return ;
	if (stack->print)
		write(1, "pa\n", 3);
	else
		++stack->moves;
	push(stack->stack_b, &stack->b_size, stack->stack_a, &stack->a_size);
}

void	pb(t_pushswap *stack)
{
	if (!stack->a_size)
		return ;
	if (stack->print)
		write(1, "pb\n", 3);
	else
		++stack->moves;
	push(stack->stack_a, &stack->a_size, stack->stack_b, &stack->b_size);
}
