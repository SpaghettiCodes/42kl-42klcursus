/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:20:26 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 13:20:27 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_pushswap *stack)
{
	if (stack->a_size < 2)
		return ;
	rotate(stack->stack_a, stack->a_size);
}

void	rb(t_pushswap *stack)
{
	if (stack->b_size < 2)
		return ;
	rotate(stack->stack_b, stack->b_size);
}

void	rr(t_pushswap *stack)
{
	ra(stack);
	rb(stack);
}
