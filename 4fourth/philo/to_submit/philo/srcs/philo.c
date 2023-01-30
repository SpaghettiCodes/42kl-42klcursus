/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:17:27 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/30 17:14:00 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_data *data, int num_threads)
{
	int	i;

	i = 0;
	while (i < num_threads)
	{
		pthread_join(data->philo_id[i], 0);
		++i;
	}
}

void	init_data(t_data *data)
{
	data->eat_count = NULL;
	data->philo_id = NULL;
	data->philo = NULL;
	data->forks = NULL;
	data->death_check = NULL;
	data->eat_check = NULL;
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	if (ac < 5 || ac > 6)
		return (eprint("Arguments Error\n"));
	init_data(&data);
	if (get_data(&data, ac, av))
		return (-1);
	i = -1;
	while (++i < data.n_philo)
	{
		if (pthread_create(&data.philo_id[i], NULL,
				(void *) philo, (void *) &data))
		{
			data.error = TRUE;
			join_threads(&data, i);
			free_alldata(&data, 1);
			return (eprint("Threading Error\n"));
		}
	}
	pthread_mutex_lock(&data.check_status);
	data.start_sim = TRUE;
	pthread_mutex_unlock(&data.check_status);
	if (check_cond(&data))
		data.start_sim = FALSE;
	join_threads(&data, data.n_philo);
	free_alldata(&data, 1);
}
