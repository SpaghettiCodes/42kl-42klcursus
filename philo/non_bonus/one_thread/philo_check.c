#include "philo.h"

int	check_count(t_data *data)
{
	int	i;

	i = 0;
	if (data->eat_count[0] == -1)
		return (0);
	while (i < data->n_philo)
	{
		if (data->eat_count[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

int	philodeath(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (data->start_sim && gettime() - data->philo[i].last_eaten > data->time_to_die)
		{
			pthread_mutex_lock(&data->death);
			print_timestamp(data, &data->philo[i], "died\n");
			data->start_sim = FALSE;
			pthread_mutex_unlock(&data->death);
			return (1);
		}
		i++;
	}
	return (0);
}

void	check_cond(t_data *data)
{
	while (data->start_sim && !philodeath(data))
	{
		if (check_count(data))
		{
			pthread_mutex_lock(&data->write_data);
			data->start_sim = FALSE;
			pthread_mutex_unlock(&data->write_data);
			break;
		}
	}
}