/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:17:18 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/20 14:19:24 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eprint(char *str)
{
	return (write(2, str, str_len(str)));
}

void	release_locks(t_philo *philo_data)
{
	if (philo_data->forks > 0)
	{
		pthread_mutex_unlock(philo_data->l_hand);
		if (philo_data->forks == 2)
			pthread_mutex_unlock(philo_data->r_hand);
	}
}