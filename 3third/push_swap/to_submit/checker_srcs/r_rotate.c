/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:20:25 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 13:20:26 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_pushswap *stack)
{
	if (stack->a_size < 2)
		return ;
	reverserotate(stack->stack_a, stack->a_size);
}

void	rrb(t_pushswap *stack)
{
	if (stack->b_size < 2)
		return ;
	reverserotate(stack->stack_b, stack->b_size);
}

void	rrr(t_pushswap *stack)
{
	rra(stack);
	rrb(stack);
}
