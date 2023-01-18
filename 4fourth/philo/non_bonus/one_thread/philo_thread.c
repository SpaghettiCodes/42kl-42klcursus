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
	philo_data->writing_data = 0;
}

void	run_sim(t_philo *philo_data, t_data *data)
{
	int	run_sim;

	if (philo_data->id % 2)
	{
		philothink(philo_data, data);
		usleep(data->time_to_eat / 2);
	}
	while (1)
	{
		pthread_mutex_lock(&data->check_status);
		run_sim = data->start_sim;
		pthread_mutex_unlock(&data->check_status);
		if (!run_sim)
			break ;
		philo_action(philo_data, data);
	}
}

int	waitforsignal(t_data *data)
{
	int	return_val;

	pthread_mutex_lock(&data->check_status);
	return_val = data->start_sim;
	pthread_mutex_unlock(&data->check_status);
	return (return_val);
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

	while (!waitforsignal(data))
	{
	}
	philo_data->start_time = gettime();
	// pthread_mutex_lock(&data->write_data);
	// printf("%ld\n", philo_data->start_time);
	// pthread_mutex_unlock(&data->write_data);
	philo_data->last_eaten = philo_data->start_time;
	run_sim(philo_data, data);
	release_locks(philo_data, data);
	return (1);
}
