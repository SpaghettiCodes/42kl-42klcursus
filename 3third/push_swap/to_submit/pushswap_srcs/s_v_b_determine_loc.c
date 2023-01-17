/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_v_b_determine_loc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:20:14 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 16:20:14 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_no_larger(t_pushswap *stack, int reference, int last_elem_loc)
{
	int	location;

	location = stack->a_size;
	while (--location >= last_elem_loc)
	{
		if (stack->stack_a[location] < reference)
			break ;
	}
	location = (stack->a_size - location - 1);
	return (location);
}

int	get_no_smaller(t_pushswap *stack, int reference, int first_elem_loc)
{
	int	location;

	location = -1;
	while (++location <= first_elem_loc)
	{
		if (stack->stack_a[location] > reference)
			break ;
	}
	return (location);
}
