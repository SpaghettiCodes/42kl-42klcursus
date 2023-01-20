/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:16:17 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/20 14:16:47 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philoeat(t_philo *philo, t_data *data)
{
	print_timestamp(data, philo, "is eating\n");
	philo->last_eaten = gettime();
	if (data->eat_count > 0)
	{
		--data->eat_count;
		if (data->eat_count == 0)
			sem_post(data->full);
	}
	usleep(data->time_to_eat);
}

void	philosleep(t_philo *philo,  t_data *data)
{
	print_timestamp(data, philo, "is sleeping\n");
	usleep(data->time_to_sleep);
}

void	philothink(t_philo *philo, t_data *data)
{
	print_timestamp(data, philo, "is thinking\n");
}

void	get_fork(t_philo *philo, t_data *data)
{
	sem_wait(data->forks);
	print_timestamp(data, philo, "has taken a fork\n");
	if (data->n_philo > 1)
	{
		sem_wait(data->forks);
		print_timestamp(data, philo, "has taken a fork\n");
	}
	philo->forks = 1 + (data->n_philo > 1);
}

void	philo_action(t_philo *philo, t_data *data)
{
	if (!philo->forks)
		get_fork(philo, data);
	if (philo->forks == 2)
	{
		philoeat(philo, data);
		sem_post(data->forks);
		sem_post(data->forks);
		philo->forks = 0;
		philosleep(philo, data);
		philothink(philo, data);
	}
}