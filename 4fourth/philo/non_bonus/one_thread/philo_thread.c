#include "philo.h"

void	philo_init(t_philo	*philo_data, t_data	*data, int id)
{
	philo_data->id = id;
	philo_data->is_thinking = FALSE;
	philo_data->forks = 0;
	philo_data->l_hand = &data->forks[id - 1];
	if (id == data->n_philo)
		philo_data->r_hand = &data->forks[0];
	else
		philo_data->r_hand = &data->forks[id];
}

void	run_sim(t_philo *philo_data, t_data *data)
{
	if (philo_data->id % 2)
	{
		philothink(philo_data, data);
		usleep(data->time_to_sleep / 2);
	}
	while (data->start_sim)
		philo_action(philo_data, data);
}

void	waitforsignal(t_data *data)
{
	while (!data->start_sim)
		if (data->start_sim)
			return ;
}

int	philo(t_data *data)
{
	t_philo	*philo_data;
	int		id;

	pthread_mutex_lock(&data->write_data);
	id = ++data->id;
	pthread_mutex_unlock(&data->write_data);

	philo_data = &data->philo[id - 1];
	philo_init(philo_data, data, id);

	waitforsignal(data);
	philo_data->start_time = gettime();
	philo_data->last_eaten = philo_data->start_time;
	run_sim(philo_data, data);
	release_locks(philo_data, data);
	return (1);
}
