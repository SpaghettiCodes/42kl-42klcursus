/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:20:29 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 17:26:06 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(int *num1, int *num2)
{
	int	temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
	return ;
}

void	sa(t_pushswap *stack)
{
	if (stack->a_size < 2)
		return ;
	swap(&stack->stack_a[0], &stack->stack_a[1]);
}

void	sb(t_pushswap *stack)
{
	if (stack->b_size < 2)
		return ;
	swap(&stack->stack_b[0], &stack->stack_b[1]);
}

void	ss(t_pushswap *stack)
{
	sa(stack);
	sb(stack);
}
