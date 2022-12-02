#include "philo.h"

// todo - write out a printmsg because printf is slow as fuuuuuuuuuuuuuu

int		str_len(char	*msg)
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

// void	print_timestamp(t_data *data, t_philo *philo_data, char *msg, int override)
// {
// 	long int	time;
// 	long int	id;
// 	int	i;

// 	time = (gettime() - philo_data->start_time) / 1000;
// 	if (data->start_sim || override)
// 	{
// 		pthread_mutex_lock(&data->write_data);
// 		id = philo_data->id;
// 		write_nbr(time);
// 		write(1, " ", 1);
// 		write_nbr(id);
// 		write(1, " ", 1);
// 		write(1, msg, str_len(msg));
// 		pthread_mutex_unlock(&data->write_data);
// 	}
// }

void	print_timestamp(t_data *data, t_philo *philo_data, char *msg, int override)
{
	long int	time;
	int	id;
	int	i;

	time = (gettime() - philo_data->start_time) / 1000;
	id = philo_data->id;
	if (data->start_sim || override)
	{
		printf("%ld %d %s", time, id, msg);
	}
}