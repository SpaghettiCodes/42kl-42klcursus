#include "philo.h"

void	philodeath(t_philo *philo_data)
{
	while (philo_data->data->start_sim)
	{
		usleep(philo_data->data->time_to_die);
		if (philo_data->data->start_sim &&
				!philo_data->is_eating && 
					(gettime() - philo_data->last_eaten) > philo_data->data->time_to_die)
		{
			pthread_mutex_lock(&philo_data->data->death);
			print_timestamp(philo_data, "died\n");
			philo_data->data->start_sim = FALSE;
			pthread_mutex_unlock(&philo_data->data->death);
			break;
		}
	}
}

void	check_full(t_data *data)
{
	while (data->start_sim)
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