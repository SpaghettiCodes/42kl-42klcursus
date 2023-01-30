/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:17:34 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/30 17:10:37 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	gettime(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		eprint("Error = unable to get time");
		return (0);
	}
	return ((time.tv_sec * 1000000) + time.tv_usec);
}
