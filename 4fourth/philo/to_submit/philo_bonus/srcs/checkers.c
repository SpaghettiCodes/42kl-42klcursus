/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:01:43 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/30 17:04:57 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	full_check(t_data *data)
{
	int	done_eating;

	done_eating = 0;
	while (done_eating < data->n_philo)
	{
		sem_wait(data->full);
		++done_eating;
	}
	sem_post(data->end);
	return ;
}

void	death_check(t_data *data, pthread_t *checker)
{
	sem_wait(data->end);
	killallchild(*data);
	pthread_join(*checker, NULL);
	freedata(data);
	exit(10);
}

void	check_death(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	while (data->start_sim)
	{
		usleep(data->time_to_die);
		if ((gettime() - philo->last_eaten) > data->time_to_die)
		{
			print_timestamp(data, philo, "died\n");
			sem_post(data->end);
			sem_wait(data->start);
			return ;
		}
	}
}
