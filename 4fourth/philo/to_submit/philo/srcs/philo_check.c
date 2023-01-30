/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:17:23 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/30 17:13:38 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_count(t_data *data)
{
	int	i;
	int	check;

	i = 0;
	usleep(data->time_to_eat);
	while (i < data->n_philo)
	{
		pthread_mutex_lock(&data->eat_check[i]);
		check = data->eat_count[i];
		pthread_mutex_unlock(&data->eat_check[i]);
		if (check != 0)
			return (0);
		++i;
	}
	pthread_mutex_lock(&data->check_status);
	data->start_sim = FALSE;
	pthread_mutex_unlock(&data->check_status);
	return (1);
}

int	philodeath(t_data *data)
{
	int	i;
	int	start_sim;
	int	last_eaten;

	i = 0;
	usleep(data->time_to_die);
	while (i < data->n_philo)
	{
		pthread_mutex_lock(&data->check_status);
		start_sim = data->start_sim;
		pthread_mutex_unlock(&data->check_status);
		pthread_mutex_lock(&data->death_check[i]);
		last_eaten = data->philo[i].last_eaten;
		pthread_mutex_unlock(&data->death_check[i]);
		if (start_sim && (gettime() - last_eaten) > data->time_to_die)
		{
			print_timestamp(data, &data->philo[i], "died\n");
			pthread_mutex_lock(&data->check_status);
			data->start_sim = FALSE;
			pthread_mutex_unlock(&data->check_status);
			return (1);
		}
		++i;
	}
	return (0);
}

void	check_death(t_data *data)
{
	int	start_sim;

	while (!philodeath(data))
	{
		pthread_mutex_lock(&data->check_status);
		start_sim = data->start_sim;
		pthread_mutex_unlock(&data->check_status);
		if (!start_sim)
			break ;
	}
}

void	check_eat(t_data *data)
{
	int	start_sim;

	while (!check_count(data))
	{
		pthread_mutex_lock(&data->check_status);
		start_sim = data->start_sim;
		pthread_mutex_unlock(&data->check_status);
		if (!start_sim)
			break ;
	}
}

int	check_cond(t_data *data)
{
	pthread_t	death_check;
	pthread_t	eat_check;

	if (pthread_create(&death_check, NULL, (void *) check_death, (void *) data))
	{
		eprint("Threading Error\n");
		return (1);
	}
	if (pthread_create(&eat_check, NULL, (void *) check_eat, (void *) data))
	{
		pthread_detach(death_check);
		eprint("Threading Error\n");
		return (1);
	}
	pthread_join(death_check, NULL);
	pthread_join(eat_check, NULL);
	return (0);
}
