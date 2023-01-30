/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:01:39 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/30 17:08:39 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	run_sim(t_philo *philo)
{
	t_data		*data;
	pthread_t	death_thread;

	data = philo->data;
	sem_wait(data->start);
	data->start_sim = TRUE;
	philo->start_time = gettime();
	philo->last_eaten = philo->start_time;
	if (pthread_create(&death_thread, 0, (void *)check_death, philo))
		return (eprint("threading failed\n"));
	if (philo->id > (data->n_philo / 2))
	{
		philothink(philo, data);
		usleep(data->time_to_eat / 2);
	}
	while (data->start_sim)
		philo_action(philo, data);
	pthread_join(death_thread, 0);
	return (0);
}

void	philo(int id, t_data *data)
{
	t_philo		philo;

	++id;
	init_philo(&philo, data, id);
	run_sim(&philo);
}

void	killallchild(t_data data)
{
	int	i;

	i = 0;
	while (i < data.n_philo)
	{
		kill(data.philo_childid[i], SIGTERM);
		sem_post(data.full);
		i++;
	}
}
