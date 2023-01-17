#include "philo.h"

int	check_count(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_lock(&data->eat_check[i]);
		if (data->eat_count[i] != 0)
		{
			pthread_mutex_unlock(&data->eat_check[i]);
			return (0);
		}
		pthread_mutex_unlock(&data->eat_check[i]);
		++i;
	}
	return (1);
}

int	philodeath(t_data *data)
{
	int	i;
	int	start_sim;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_lock(&data->check_status);
		start_sim = data->start_sim;
		pthread_mutex_unlock(&data->check_status);

		pthread_mutex_lock(&data->death_check[i]);
		if (start_sim && gettime() - data->philo[i].last_eaten > data->time_to_die)
		{
			pthread_mutex_lock(&data->death);
			print_timestamp(data, &data->philo[i], "died\n");
			pthread_mutex_lock(&data->check_status);
			data->start_sim = FALSE;
			pthread_mutex_unlock(&data->check_status);
			pthread_mutex_unlock(&data->death);
			pthread_mutex_unlock(&data->death_check[i]);
			return (1);
		}
		pthread_mutex_unlock(&data->death_check[i]);
		i++;
	}
	return (0);
}

void	check_cond(t_data *data)
{
	int	start_sim;

	while (!philodeath(data))
	{
		pthread_mutex_lock(&data->check_status);
		start_sim = data->start_sim;
		pthread_mutex_unlock(&data->check_status);
		if (!start_sim)
			break;
		if (check_count(data))
		{
			pthread_mutex_lock(&data->check_status);
			data->start_sim = FALSE;
			pthread_mutex_unlock(&data->check_status);
			break;
		}
	}
}