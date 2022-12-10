#include "philo.h"

void	philoeat(t_philo *philo_data, t_data *data)
{
	print_timestamp(data, philo_data, "is eating\n");
	philo_data->last_eaten = gettime();
	// debug purposes
	// philo_data->start_time = philo_data->last_eaten;
	if (data->eat_count[philo_data->id - 1] > 0)
		data->eat_count[philo_data->id - 1]--;
	usleep(data->time_to_eat);
}

void	philosleep(t_philo *philo_data,  t_data *data)
{
	print_timestamp(data, philo_data, "is sleeping\n");
	usleep(data->time_to_sleep);
}

void	philothink(t_philo *philo_data, t_data *data)
{
	print_timestamp(data, philo_data, "is thinking\n");
}

void	get_fork(t_philo *philo_data, t_data *data)
{
	pthread_mutex_lock(philo_data->l_hand);
	print_timestamp(data, philo_data, "has taken a fork\n");
	philo_data->forks++;
	if (philo_data->r_hand != philo_data->l_hand)
	{
		pthread_mutex_lock(philo_data->r_hand);
		print_timestamp(data, philo_data, "has taken a fork\n");
		philo_data->forks++;
	}
}

void	philo_action(t_philo *philo_data, t_data *data)
{
	// get fork
	if (!philo_data->forks)
		get_fork(philo_data, data);
	if (philo_data->forks == 2)
	{
		philoeat(philo_data, data);
		// return fork
		pthread_mutex_unlock(philo_data->l_hand);
		pthread_mutex_unlock(philo_data->r_hand);
		philo_data->forks = 0;
		// sleep and think
		philosleep(philo_data, data);
		philothink(philo_data, data);
	}
}