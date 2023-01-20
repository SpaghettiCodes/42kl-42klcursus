/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:16:32 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/20 14:16:33 by cshi-xia         ###   ########.fr       */
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

void	print_timestamp(t_data *data, t_philo *philo, char *msg)
{
	long int	time;
	long int	id;

	time = (gettime() - philo->start_time) / 1000;
	id = philo->id;
	sem_wait(data->write);
	philo->is_writing = TRUE;
	sem_wait(data->start);
	sem_post(data->start);
	printf("%ld %ld %s", time, id, msg);
	sem_post(data->write);
	philo->is_writing = FALSE;
}