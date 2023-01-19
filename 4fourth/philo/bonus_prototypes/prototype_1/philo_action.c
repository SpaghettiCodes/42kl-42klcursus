#include "philo.h"

void	philoeat(t_philo *philo, t_data *data)
{
	print_timestamp(data, philo, "is eating\n");
	philo->last_eaten = gettime();
	// debug purposes
	// philo->start_time = philo->last_eaten;
	if (data->eat_count > 0)
	{
		--data->eat_count;
		if (data->eat_count == 0)
			sem_post(data->full);
	}
	usleep(data->time_to_eat);
}

void	philosleep(t_philo *philo,  t_data *data)
{
	print_timestamp(data, philo, "is sleeping\n");
	usleep(data->time_to_sleep);
}

void	philothink(t_philo *philo, t_data *data)
{
	print_timestamp(data, philo, "is thinking\n");
}

void	get_fork(t_philo *philo, t_data *data)
{
	sem_wait(data->forks);
	print_timestamp(data, philo, "has taken a fork\n");
	if (data->n_philo > 1)
	{
		sem_wait(data->forks);
		print_timestamp(data, philo, "has taken a fork\n");
	}
	philo->forks = 1 + (data->n_philo > 1);
}

void	philo_action(t_philo *philo, t_data *data)
{
	// get fork
	if (!philo->forks)
		get_fork(philo, data);
	if (philo->forks == 2)
	{
		philoeat(philo, data);
		// return fork
		sem_post(data->forks);
		sem_post(data->forks);
		philo->forks = 0;
		// sleep and think
		philosleep(philo, data);
		philothink(philo, data);
	}
}