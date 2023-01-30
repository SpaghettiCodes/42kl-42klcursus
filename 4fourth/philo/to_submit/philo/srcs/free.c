#include "philo.h"

void	free_mutex_table(pthread_mutex_t *table, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&table[i]);
		++i;
	}
	free(table);
}

void	free_alldata(t_data *data, char mutex_inited)
{
	if (data->death_check)
		free_mutex_table(data->death_check, data->n_philo);
	if (data->eat_check)
		free_mutex_table(data->eat_check, data->n_philo);
	if (data->forks)
		free_mutex_table(data->forks, data->n_philo);
	if (mutex_inited)
	{
		pthread_mutex_destroy(&data->check_status);
		pthread_mutex_destroy(&data->read_data);
		pthread_mutex_destroy(&data->death);
		pthread_mutex_destroy(&data->write_data);
	}
	free(data->eat_count);
	free(data->philo_id);
	free(data->philo);
}
