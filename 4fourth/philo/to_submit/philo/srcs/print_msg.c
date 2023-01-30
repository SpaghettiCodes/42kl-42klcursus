/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:17:30 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/21 17:14:14 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		str_len(char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
		i++;
	return (i);
}

void	write_nbr(long int time)
{
	if (time >= 10)
		write_nbr(time / 10);
	write(1, &"0123456789"[time % 10], 1);
}

void	print_timestamp(t_data *data, t_philo *philo_data, char *msg)
{
	int			start_sim;
	long int	time;
	long int	id;

	id = philo_data->id;
	time = (gettime() - philo_data->start_time) / 1000;

	pthread_mutex_lock(&data->write_data);
	pthread_mutex_lock(&data->check_status);
	start_sim = data->start_sim;
	pthread_mutex_unlock(&data->check_status);
	if (start_sim)
	{
		write_nbr(time);
		write(1, " ", 1);
		write_nbr(id);
		write(1, " ", 1);
		write(1, msg, str_len(msg));
	}
	pthread_mutex_unlock(&data->write_data);
}