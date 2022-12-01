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
	struct timeval time;
	gettimeofday(&time, NULL);

	return ((time.tv_sec * 1000000) + time.tv_usec);
}

void	philo_init(t_philo	*philo_data, t_data	*data)
{
	philo_data->is_thinking = FALSE;
	philo_data->id = ++data->id;
	philo_data->can_eat = FALSE;
	if (philo_data->id == data->n_philo)
		philo_data->next_id = 1;
	else
		philo_data->next_id = philo_data->id + 1;
}

void	philoeat(t_data *data, t_philo *philo_data)
{
	if (data->start_sim)
	{
		print_timestamp(data, philo_data, "is eating\n");
		philo_data->last_eaten = gettime();
		// philo_data->start_time = philo_data->last_eaten;
		if (data->eat_count[philo_data->id - 1] > 0)
			data->eat_count[philo_data->id - 1]--;
		usleep(data->time_to_eat);
	}
}

void	philosleep(t_data *data, t_philo *philo_data)
{
	if (data->start_sim)
	{
		print_timestamp(data, philo_data, "is sleeping\n");
		usleep(data->time_to_sleep);
	}
}

int	philodeath(void *arg)
{
	t_arg	*package;
	t_data	*data;
	t_philo	*philo_data;

	package = (t_arg *) arg;
	data = package->data;
	philo_data = package->philo_data;
	while (data->start_sim)
	{
		usleep(data->time_to_die);
		if (data->start_sim && !philo_data->can_eat && (gettime() - philo_data->last_eaten) > data->time_to_die)
		{
			data->start_sim = FALSE;
			print_timestamp(data, philo_data, "died\n");
			break;
		}
	}
	return (0);
}

void	philothink(t_data *data, t_philo *philo_data)
{
	if (data->start_sim)
		print_timestamp(data, philo_data, "is thinking\n");
}

void	get_fork(t_data *data, t_philo *philo_data)
{
	// get fork
	if (!philo_data->can_eat && philo_data->id != philo_data->next_id)
	{
		pthread_mutex_lock(&data->forks[philo_data->id - 1]);
		print_timestamp(data, philo_data, "has taken a fork\n");
		pthread_mutex_lock(&data->forks[philo_data->next_id - 1]);
		print_timestamp(data, philo_data, "has taken a fork\n");
		philo_data->can_eat = TRUE;
		return ;
	}

	if (philo_data->can_eat)
	{
		philo_data->can_eat = FALSE;
		philoeat(data, philo_data);

		// return fork
		pthread_mutex_unlock(&data->forks[philo_data->id - 1]);
		pthread_mutex_unlock(&data->forks[philo_data->next_id - 1]);

		philosleep(data, philo_data);
		philothink(data, philo_data);
		return ; 
	}
}

int	check_count(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (data->eat_count[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

void	check_full(void *arg)
{
	t_data *data;

	data = (t_data *) arg;
	while (1)
	{
		if (check_count(data))
		{
			data->start_sim = FALSE;
			break;
		}
	}
}

void	run_sim(void *arg)
{
	t_data	*data;
	t_philo *philo_data;
	t_arg	*package;

	package = (t_arg *) arg;
	data = package->data;
	philo_data = package->philo_data;
	if (philo_data->id % 2)
	{
		philothink(data, philo_data);
		usleep(data->time_to_sleep / 2);
	}
	while (data->start_sim)
		get_fork(data, philo_data);
}

int	philo(void *arg)
{
	t_data	*data;
	t_philo	philo_data;
	t_arg	package;

	data = (t_data *) arg;
	philo_init(&philo_data, data);

	package.philo_data = &philo_data;
	package.data = data;
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
	pthread_create(&philo_data.main_thread, NULL, (void *)run_sim, &package);
	pthread_create(&philo_data.death_thread, NULL, (void *)philodeath, &package);
	pthread_create(&philo_data.check_thread, NULL, (void *)check_full, data);
	pthread_join(philo_data.check_thread, NULL);
	pthread_join(philo_data.main_thread, NULL);
	pthread_join(philo_data.death_thread, NULL);
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

void	init_data(t_data *data, int	n_philo, int time_to_die, int time_to_eat, int time_to_sleep, int eat_count)
{
	data->id = 0;
	data->n_philo = n_philo;
	data->time_to_die = time_to_die;
	data->time_to_sleep = time_to_sleep;
	data->time_to_eat = time_to_eat;

	data->eat_count = init_eatcount(n_philo, eat_count);
	data->forks = init_forks(n_philo);
	data->start_sim = FALSE;
	data->philo_id = malloc ((sizeof(pthread_t) * n_philo));

	pthread_mutex_init(&data->pick_fork, NULL);
	pthread_mutex_init(&data->write_data, NULL);
}

int	main(int ac, char **av)
{
	int	n_philo = 4;
	int	time_to_die = 410;
	int	time_to_eat = 200;
	int	time_to_sleep = 200;
	int	eat_count = 3;
	t_data	data;
	int	i;

	time_to_die *= 1000;
	time_to_eat *= 1000;
	time_to_sleep *= 1000;
	init_data(&data, n_philo, time_to_die, time_to_eat, time_to_sleep, eat_count);
	i = 0;
	while (i < n_philo)
	{
		pthread_create(&data.philo_id[i], NULL, (void *) philo, (void *) &data);
		i++;
	}
	i = 0;
	while (i < n_philo)
	{
		pthread_join(data.philo_id[i], NULL);
		i++;
	}
	free(data.forks);
	free(data.eat_count);
	free(data.philo_id);
}