#include "philo.h"

void	create_subthreads(t_philo *philo_data)
{
	pthread_create(&philo_data->main_thread, NULL, (void *)run_sim, philo_data);
	pthread_create(&philo_data->death_thread, NULL, (void *)philodeath, philo_data);
	pthread_create(&philo_data->check_thread, NULL, (void *)check_full, philo_data->data);

}

void	join_subthreads(t_philo *philo_data)
{
	pthread_join(philo_data->death_thread, NULL);
	pthread_join(philo_data->check_thread, NULL);
	pthread_join(philo_data->main_thread, NULL);
}
