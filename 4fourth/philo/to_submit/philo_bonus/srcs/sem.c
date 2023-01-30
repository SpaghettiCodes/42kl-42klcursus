#include "philo.h"

void	open_sem(t_data *data)
{
	data->forks = sem_open("/forks", O_CREAT, S_IRWXG | S_IRWXO | S_IRWXU, data->n_philo);
	data->write = sem_open("/write", O_CREAT, S_IRWXG | S_IRWXO | S_IRWXU, 1);
	data->start = sem_open("/start", O_CREAT, S_IRWXG | S_IRWXO | S_IRWXU, 1);
	data->end = sem_open("/end", O_CREAT, S_IRWXG | S_IRWXO | S_IRWXU, 0);
	data->full = sem_open("/full", O_CREAT, S_IRWXG | S_IRWXO | S_IRWXU, 0);
}

void	unlink_sems(void)
{
	sem_unlink("/forks");
	sem_unlink("/write");
	sem_unlink("/end");
	sem_unlink("/start");
	sem_unlink("/full");
}