/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:01:53 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/31 17:54:03 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, int ac, char **av)
{
	if (ac < 5)
		return (eprint("Not enough arguments\n"));
	else if (ac > 6)
		return (eprint("Too much arguments\n"));
	data->n_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]) * 1000;
	data->time_to_eat = ft_atoi(av[3]) * 1000;
	data->time_to_sleep = ft_atoi(av[4]) * 1000;
	if (data->time_to_die <= 0 || data->time_to_eat <= 0
		|| data->time_to_sleep <= 0)
		return (eprint("Invalid Arguments\n"));
	data->eat_count = -1;
	if (ac == 6)
	{
		data->eat_count = ft_atoi(av[5]);
		if (data->eat_count <= 0)
			return (eprint("Invalid Eat Count\n"));
	}
	data->philo_childid = malloc (sizeof(pid_t) * data->n_philo);
	if (!data->philo_childid)
		return (eprint("malloced failed\n"));
	open_sem(data);
	data->start_sim = FALSE;
	return (0);
}

void	init_philo(t_philo *philo, t_data *data, int id)
{
	philo->data = data;
	philo->id = id;
	philo->forks = 0;
	philo->is_eating = FALSE;
	philo->is_writing = FALSE;
}
