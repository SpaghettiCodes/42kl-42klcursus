/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:18:52 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 18:58:05 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(t_pushswap *stack, char **free_me, int *free_me_2)
{
	if (stack)
		freeall(stack);
	if (free_me)
		freedoublechar(free_me);
	if (free_me_2)
		free(free_me_2);
	write(2, "Error\n", 6);
	exit(69);
	return (420);
}
