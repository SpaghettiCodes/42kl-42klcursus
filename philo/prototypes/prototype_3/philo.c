#include "philo.h"

/*
** Wow new prototype
** change the fork into mutex locks because
** "Change of the flag is just few instructions and normally done without system call. If mutex is locked, syscall will happen to 
** add the calling thread into wait queue and start the waiting. Unlocking, if the wait queue is empty, is cheap but 
** otherwise needs a syscall to wake up one of the waiting processes.
** Locking unlocked mutex is really cheap. Unlocking mutex w/o contention is cheap too."
*/

/*
** Atomic counter is apparantly faster? but i cant use atomic variables soooooooooo
*/


/*
** Update 2
** I am a clown
** Changing to mutex does not fix the problem
** Now half of my philo decides to think abit before eating their spagehti
** making this change FIXES the damn problem
** and now even the older version works
** jesus chirst i wanna cry
** GOD if only we can use pthread_mutex_trylock
*/

// typedef struct s_timeval 
// {
// 	time_t      tv_sec;     /* seconds */
// 	suseconds_t tv_usec;    /* microseconds */
// } t_timeval;

long int	gettime()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000000) + time.tv_usec);
}

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

void	philoeat(t_philo *philo_data)
{
	print_timestamp(philo_data, "is eating\n");
	philo_data->last_eaten = gettime();
	// debug purposes
	// philo_data->start_time = philo_data->last_eaten;
	if (philo_data->data->eat_count[philo_data->id - 1] > 0)
		philo_data->data->eat_count[philo_data->id - 1]--;
	usleep(philo_data->data->time_to_eat);
}

void	philosleep(t_philo *philo_data)
{
	print_timestamp(philo_data, "is sleeping\n");
	usleep(philo_data->data->time_to_sleep);
}

void	philodeath(t_philo *philo_data)
{
	while (philo_data->data->start_sim)
	{
		usleep(philo_data->data->time_to_die);
		if (philo_data->data->start_sim &&
				!philo_data->is_eating && 
					(gettime() - philo_data->last_eaten) > philo_data->data->time_to_die)
		{
			pthread_mutex_lock(&philo_data->data->death);
			print_timestamp(philo_data, "died\n");
			philo_data->data->start_sim = FALSE;
			pthread_mutex_unlock(&philo_data->data->death);
			break;
		}
	}
}

void	philothink(t_philo *philo_data)
{
	print_timestamp(philo_data, "is thinking\n");
}

void	get_fork(t_philo *philo_data)
{
	pthread_mutex_lock(philo_data->l_hand);
	print_timestamp(philo_data, "has taken a fork\n");
	philo_data->forks++;
	if (philo_data->r_hand != philo_data->l_hand)
	{
		pthread_mutex_lock(philo_data->r_hand);
		print_timestamp(philo_data, "has taken a fork\n");
		philo_data->forks++;
	}
}

void	philo_action(t_philo *philo_data)
{
	// get fork
	if (!philo_data->forks)
		get_fork(philo_data);
	if (philo_data->forks == 2)
	{
		philo_data->is_eating = TRUE;
		philoeat(philo_data);
		philo_data->is_eating = FALSE;
		// return fork
		pthread_mutex_unlock(philo_data->l_hand);
		pthread_mutex_unlock(philo_data->r_hand);
		philo_data->forks = 0;
		// sleep and think
		philosleep(philo_data);
		philothink(philo_data);
	}
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

void	check_full(t_data *data)
{
	while (data->start_sim)
	{
		if (check_count(data))
		{
			pthread_mutex_lock(&data->write_data);
			data->start_sim = FALSE;
			pthread_mutex_unlock(&data->write_data);
			break;
		}
	}
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

void	release_locks(t_philo *philo_data)
{
	pthread_mutex_unlock(philo_data->l_hand);
	pthread_mutex_unlock(philo_data->r_hand);
	pthread_mutex_unlock(&philo_data->data->write_data);
	pthread_mutex_unlock(&philo_data->data->death);
}

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

int	eprint(char *str)
{
	return (write(2, str, str_len(str)));
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