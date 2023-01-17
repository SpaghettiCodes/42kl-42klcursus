/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:20:23 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 17:22:00 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_pushswap *stack)
{
	if (!stack->b_size)
		return ;
	push(stack->stack_b, &stack->b_size, stack->stack_a, &stack->a_size);
}

void	pb(t_pushswap *stack)
{
	if (!stack->a_size)
		return ;
	push(stack->stack_a, &stack->a_size, stack->stack_b, &stack->b_size);
}
