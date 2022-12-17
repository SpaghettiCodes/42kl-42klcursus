#include "philo.h"

// BONUS PART
// ----------

// Philo_bonus code
// ----------------
// - Check the code of philo_bonus for the following things and ask for an explanation.
// - Check if there will be one process per philosopher and that the first process waits for all of them.
// - Check if there is a single semaphore that represents the number of forks.
// - Check if the output is protected against multiple access. To avoid a scrambled view.
// - Check how the death of a philosopher is checked and if there is a semaphore to protect that a philosopher dies and starts eating at the same time.

// Philo_bonus test
// ----------------
// - Do not test with more than 200 philosophers
// - Do not test with time_to_die or time_to_eat or time_to_sleep under 60 ms
// - Test with 5 800 200 200, no one should die!
// - Test with 5 800 200 200 7, no one should die and the simulation should stop when all the philosopher has eaten at least 7 times each.
// - Test with 4 410 200 200, no one should die!
// - Test with 4 310 200 100, a philosopher should die!
// - Test with 2 philosophers and check the different times (a death delayed by more than 10 ms is unacceptable).
// - Test with your values to check all the rules. Check if a philosopher dies at the right time if they don't steal forks, etc.

long int	gettime()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000000) + time.tv_usec);
}

int	eprint(char	*str)
{
	return(write(2, str, str_len(str)));
}

void	open_sem(t_data *data)
{
	data->forks = sem_open("/forks", O_CREAT, S_IRWXG | S_IRWXO | S_IRWXU, data->n_philo);
	data->write = sem_open("/write", O_CREAT, S_IRWXG | S_IRWXO | S_IRWXU, 1);
	data->start = sem_open("/start", O_CREAT, S_IRWXG | S_IRWXO | S_IRWXU, 1);
	data->end = sem_open("/end", O_CREAT, S_IRWXG | S_IRWXO | S_IRWXU, 0);
	data->full = sem_open("/full", O_CREAT, S_IRWXG | S_IRWXO | S_IRWXU, 0);
}

int	init_data(t_data *data, int ac, char **av)
{
	data->n_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]) * 1000;
	data->time_to_eat = ft_atoi(av[3]) * 1000;
	data->time_to_sleep = ft_atoi(av[4]) * 1000;
	if (ac == 6)
	{
		data->eat_count = ft_atoi(av[5]);
		if (data->eat_count <= 0)
			return (eprint("Invalid Eat Count\n"));
	}
	else
		data->eat_count = -1;
	data->philo_childid = malloc (sizeof(pid_t) * data->n_philo);
	open_sem(data);
	data->start_sim = FALSE;
	return (0);
}

void	init_philo(t_philo *philo, t_data *data, int id)
{
	philo->id = id;
	philo->data = data;
	philo->forks = 0;
	philo->is_eating = FALSE; 
	philo->is_writing = FALSE;
}

void	run_sim(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	sem_wait(data->start);
	data->start_sim = TRUE;
	philo->start_time = gettime();
	philo->last_eaten = philo->start_time;
	if (philo->id > (data->n_philo / 2))
	{
		philothink(philo, data);
		usleep(data->time_to_eat / 2);
	}
	while (data->start_sim)
		philo_action(philo, data);
}

void	wait_sig(t_data *data)
{
	while (!data->start_sim)
		if (data->start_sim)
			break;
}

int	check_death(t_philo *philo, t_data *data)
{
	// printf("hyok\n");
	wait_sig(data);
	usleep(10000);
	while (data->start_sim)
	{
		if (gettime() - philo->last_eaten > data->time_to_die)
		{
			print_timestamp(data, philo, "died\n");
			data->start_sim = FALSE;
			sem_wait(data->start);
			sem_post(data->end);
			exit (1);
		}
	}
}

int philo(int id, t_data *data)
{
	t_philo philo;
	pthread_t sim;

	++id;
	init_philo(&philo, data, id);
	pthread_create(&sim, 0, (void *)run_sim, &philo);
	check_death(&philo, data);
}

void	killallchild(t_data data)
{
	int	i;

	i = 0;
	while (i < data.n_philo)
	{
		kill(data.philo_childid[i], SIGTERM);
		// printf("Killed child\n");
		i++;
	}
}

void	freedata(t_data *data)
{
	free(data->philo_childid);
	sem_close(data->forks);
	sem_close(data->start);
	sem_close(data->write);
	sem_close(data->end);
	sem_close(data->full);
}

void	full_check(t_data *data)
{
	int	done_eating;
	
	done_eating = 0;
	while (done_eating < data->n_philo)
	{
		sem_wait(data->full);
		done_eating++;
	}
	killallchild(*data);
	freedata(data);
	exit(10);
}

void	death_check(t_data *data)
{
	sem_wait(data->end);
	killallchild(*data);
	freedata(data);
	exit(10);
}

void	unlink_sems(void)
{
	sem_unlink("/forks");
	sem_unlink("/write");
	sem_unlink("/end");
	sem_unlink("/start");
	sem_unlink("/full");
}

int	main(int ac, char **av)
{
	t_data		data;
	pthread_t	checker;
	int			i;
	int			ended;

	unlink_sems();
	if (ac < 5)
		return (eprint("Not enough arguments\n"));
	else if (ac > 6)
		return (eprint("Too much arguments\n"));
	if (init_data(&data, ac, av))
		return (-1);
	i = 0;
	while (i < data.n_philo)
	{
		data.philo_childid[i] = fork();
		if (!data.philo_childid[i])
		{
			philo(i, &data);
			exit(10);
		}
		else
			i++;
	}
	i = -1;
	while (++i < data.n_philo)
		sem_post(data.start);
	pthread_create(&checker, NULL, (void *)full_check, &data);
	death_check(&data);
}
