#include "philo.h"

pthread_mutex_t	*init_mutex_table(int count)
{
	pthread_mutex_t	*table;
	int				i;

	table = malloc (sizeof(pthread_mutex_t) * count);
	if (!table)
	{
		write(2, "malloc failed\n", 14);
		return (NULL);
	}
	i = 0; 
	while (i < count)
	{
		if (init_mutex(&table[i]))
		{
			while (--i > -1)
				pthread_mutex_destroy(&table[i]);
			free(table);
			return (NULL);
		}
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
	if (!ret)
	{
		write(2, "malloc failed\n", 14);
		return (NULL);
	}
	while (i < n_philo)
	{
		ret[i] = eat_count;
		i++;
	}
	return (ret);
}

int	init_mutex(pthread_mutex_t *to_init)
{
	if (pthread_mutex_init(to_init, NULL))
	{
		write(2, "Mutex Initialization Failed\n", 28);
		return (1);
	}
	return (0);
}

int	init_mutexes(t_data *data)
{
	data->forks = init_mutex_table(data->n_philo);
	data->death_check = init_mutex_table(data->n_philo);
	data->eat_check = init_mutex_table(data->n_philo);

	if (!data->forks || !data->death_check || !data->eat_check
		|| init_mutex(&data->check_status) || init_mutex(&data->read_data) 
		|| init_mutex(&data->death) || init_mutex(&data->write_data))
	{
		free_alldata(data, 0);
		return (1);
	}
	return (0);
}

int	init_args(t_data *data, int ac, char **av)
{
	int	eat_count;

	data->n_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]) * 1000;
	data->time_to_eat = ft_atoi(av[3]) * 1000;
	data->time_to_sleep = ft_atoi(av[4]) * 1000;
	if (data->time_to_die <= 0 || data->time_to_eat <= 0
		|| data->time_to_sleep <= 0 || data->n_philo <= 0)
		return (eprint("Invalid Argument Value\n"));
	eat_count = -1;
	if (ac == 6)
	{
		eat_count = ft_atoi(av[5]);
		if (eat_count <= 0)
			return (eprint("Invalid Eat Count\n"));
	}
	data->eat_count = init_eatcount(data->n_philo, eat_count);
	if (!data->eat_count)
		return (1);
	return (0);
}

int	get_data(t_data *data, int ac, char **av)
{
	data->id = 0;
	data->error = FALSE;
	if (init_args(data, ac, av))
		return (1);
	data->start_sim = FALSE;
	data->philo = malloc (sizeof(t_philo) * data->n_philo);
	if (!data->philo)
		return (eprint("malloc failed\n"));
	data->philo_id = malloc ((sizeof(pthread_t) * data->n_philo));
	if (!data->philo_id)
		return (eprint("malloc failed\n"));
	return (init_mutexes(data));
}
