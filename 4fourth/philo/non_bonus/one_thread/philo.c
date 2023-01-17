#include "philo.h"

pthread_mutex_t *init_mutex_table(int count)
{
	pthread_mutex_t	*table;
	int		i;

	table = malloc (sizeof(pthread_mutex_t) * count);
	i = 0; 
	while (i < count)
	{
		pthread_mutex_init(&table[i], NULL);
		i++;
	}
	return (table);
}

int	*init_eatcount(int n_philo, int eat_count)
{
	int	i;
	int	*ret;

	i = 0;
	ret = malloc (sizeof(int) * n_philo);
	while (i < n_philo)
	{
		ret[i] = eat_count;
		i++;
	}
	return (ret);
}

int	init_data(t_data *data, int ac, char **av)
{
	int	eat_count;

	data->id = 0;
	data->n_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]) * 1000;
	data->time_to_eat = ft_atoi(av[3]) * 1000;
	data->time_to_sleep = ft_atoi(av[4]) * 1000;
	if (data->time_to_die <= 0 || data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		return (eprint("Invalid Argument Value!\n"));
	if (ac == 6)
	{
		eat_count = ft_atoi(av[5]);
		if (eat_count <= 0)
			return (eprint("Invalid Eat Count\n"));
	}
	else
		eat_count = -1;
	data->philo = malloc (sizeof(t_philo) * data->n_philo);
	data->eat_count = init_eatcount(data->n_philo, eat_count);
	data->forks = init_mutex_table(data->n_philo);
	data->death_check = init_mutex_table(data->n_philo);
	data->eat_check = init_mutex_table(data->n_philo);
	data->start_sim = FALSE;
	data->philo_id = malloc ((sizeof(pthread_t) * data->n_philo));
	pthread_mutex_init(&data->check_status, NULL);
	pthread_mutex_init(&data->read_data, NULL);
	pthread_mutex_init(&data->death, NULL);
	pthread_mutex_init(&data->write_data, NULL);
	return (0);
}

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

void	free_alldata(t_data *data)
{
	free_mutex_table(data->death_check, data->n_philo);
	free_mutex_table(data->eat_check, data->n_philo);
	free_mutex_table(data->forks, data->n_philo);
	pthread_mutex_destroy(&data->check_status);
	pthread_mutex_destroy(&data->read_data);
	pthread_mutex_destroy(&data->death);
	pthread_mutex_destroy(&data->write_data);
	free(data->eat_count);
	free(data->philo_id);
	free(data->philo);
}

int	main(int ac, char **av)
{
	t_data	data;
	int	i;

	if (ac < 5)
		return (eprint("Not enough arguments\n"));
	else if (ac > 6)
		return (eprint("Too much arguments\n"));
	if (init_data(&data, ac, av))
		return (-1);
	i = 0;
	while (i < data.n_philo)
	{
		pthread_create(&data.philo_id[i], NULL, (void *) philo, (void *) &data);
		i++;
	}	

	pthread_mutex_lock(&data.check_status);
	data.start_sim = TRUE;
	pthread_mutex_unlock(&data.check_status);

	usleep(data.time_to_die);
	check_cond(&data);
	i = 0;
	while (i < data.n_philo)
	{
		pthread_join(data.philo_id[i], 0);
		i++;
	}
	free_alldata(&data);
}