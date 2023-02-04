/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:16:29 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/02/04 14:11:53 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	freedata(t_data *data)
{
	free(data->philo_childid);
	sem_close(data->forks);
	sem_close(data->start);
	sem_close(data->write);
	sem_close(data->end);
	sem_close(data->full);
}

int	main(int ac, char **av)
{
	t_data		data;
	pthread_t	checker;
	int			i;

	unlink_sems();
	if (init_data(&data, ac, av))
		return (-1);
	i = 0;
	while (i < data.n_philo)
	{
		data.philo_childid[i] = fork();
		if (!data.philo_childid[i])
		{
			philo(i, &data);
			exit(10);
		}
		else
			++i;
	}
	i = -1;
	while (++i < data.n_philo)
		sem_post(data.start);
	pthread_create(&checker, NULL, (void *)full_check, &data);
	death_check(&data, &checker);
	pthread_join(&checker, NULL);
	freedata(&data);
}
