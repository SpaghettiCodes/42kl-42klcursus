#include "philo.h"

pthread_mutex_t	*init_forks(int n_philo)
{
	pthread_mutex_t	*fork_table;
	int		i;

	fork_table = malloc (sizeof(pthread_mutex_t) * n_philo);
	i = 0; 
	while (i < n_philo)
	{
		pthread_mutex_init(&fork_table[i], NULL);
		i++;
	}
	return (fork_table);
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
	if (ac == 6)
	{
		eat_count = ft_atoi(av[5]);
		if (eat_count <= 0)
			return (eprint("Invalid Eat Count\n"));
	}
	else
		eat_count = -1;

	data->eat_count = init_eatcount(data->n_philo, eat_count);
	data->forks = init_forks(data->n_philo);
	data->start_sim = FALSE;
	data->philo_id = malloc ((sizeof(pthread_t) * data->n_philo));

	pthread_mutex_init(&data->death, NULL);
	pthread_mutex_init(&data->write_data, NULL);
	return (0);
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
	i = 0;
	while (i < data.n_philo)
	{
		pthread_join(data.philo_id[i], 0);
		i++;
	}
	pthread_mutex_destroy(&data.death);
	pthread_mutex_destroy(&data.write_data);
	free(data.forks);
	free(data.eat_count);
	free(data.philo_id);
}