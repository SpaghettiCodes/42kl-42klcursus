#include "philo.h"

int	eprint(char *str)
{
	return (write(2, str, str_len(str)));
}

void	release_locks(t_philo *philo_data)
{
	pthread_mutex_unlock(philo_data->l_hand);
	pthread_mutex_unlock(philo_data->r_hand);
	pthread_mutex_unlock(&philo_data->data->write_data);
	pthread_mutex_unlock(&philo_data->data->death);
}