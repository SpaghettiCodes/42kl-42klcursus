#include "philo.h"

int	eprint(char *str)
{
	return (write(2, str, str_len(str)));
}

void	release_locks(t_philo *philo_data, t_data *data)
{
	if (philo_data->forks > 0)
	{
		pthread_mutex_unlock(philo_data->l_hand);
		if (philo_data->forks == 2)
			pthread_mutex_unlock(philo_data->r_hand);
	}
}