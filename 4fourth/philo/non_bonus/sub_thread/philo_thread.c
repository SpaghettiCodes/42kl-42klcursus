#include "philo.h"

void	philo_init(t_philo	*philo_data, t_data	*data)
{
	pthread_mutex_lock(&data->write_data);
	philo_data->id = ++data->id;
	pthread_mutex_unlock(&data->write_data);
	philo_data->is_thinking = FALSE;
	philo_data->is_eating = FALSE;
	philo_data->data = data;
	philo_data->forks = 0;
	philo_data->l_hand = &data->forks[philo_data->id - 1];
	if (philo_data->id == data->n_philo)
		philo_data->r_hand = &data->forks[0];
	else
		philo_data->r_hand = &data->forks[philo_data->id];
}

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

void	run_sim(t_philo *philo_data)
{
	if (philo_data->id % 2)
	{
		philothink(philo_data);
		usleep(philo_data->data->time_to_sleep / 2);
	}
	while (philo_data->data->start_sim)
		philo_action(philo_data);
}

int	philo(void *arg)
{
	t_data	*data;
	t_philo	philo_data;

	data = (t_data *) arg;
	philo_init(&philo_data, data);

	if (philo_data.id == data->n_philo)
		data->start_sim = TRUE;
	else
	{
		while (!data->start_sim)
			if (data->start_sim)
				break;
	}
	philo_data.start_time = gettime();
	philo_data.last_eaten = philo_data.start_time;
	create_subthreads(&philo_data);
	join_subthreads(&philo_data);
	release_locks(&philo_data);
	return (1);
}
