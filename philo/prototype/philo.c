#include "philo.h"

// typedef struct s_timeval 
// {
// 	time_t      tv_sec;     /* seconds */
// 	suseconds_t tv_usec;    /* microseconds */
// } t_timeval;

#define TAKEN 0
#define RETURNED 1
#define FALSE 0
#define TRUE 1
typedef	unsigned char bool;


// not fast enough
typedef	struct s_philo
{
	int			id;
	int			next_id;
	long int	start_time;
	long int	last_eaten;
	bool		can_eat;
	bool		is_thinking;
} t_philo;

typedef struct s_data
{
	int				id;
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long int		start_time;
	pthread_t		*philo_id;

	bool			start_sim;
	bool			someone_died;
	pthread_mutex_t	died_lock;
	bool			*forks;
	pthread_mutex_t	take_fork;
	pthread_mutex_t return_fork;
} t_data;

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
	printf("%ld %d is eating\n", (gettime() - philo_data->start_time) / 1000, philo_data->id);
	philo_data->last_eaten = gettime();
	usleep(data->time_to_eat);
}

void	philosleep(t_data *data, t_philo *philo_data)
{
	printf("%ld %d is sleeping\n", (gettime() - philo_data->start_time) / 1000, philo_data->id);
	usleep(data->time_to_sleep);
	printf("%ld %d woke up\n", (gettime() - philo_data->start_time) / 1000, philo_data->id);
}

void	ahfucksomeonedied(t_data *data, t_philo *philo_data)
{
	data->someone_died = TRUE;
	printf("%ld %d died\n", (gettime() - philo_data->start_time) / 1000, philo_data->id);
	exit(10);
}

void	philothink(t_data *data, t_philo *philo_data)
{
	if (philo_data->is_thinking == FALSE)
	{
		printf("%ld %d is thinking\n", (gettime() - philo_data->start_time) / 1000, philo_data->id);
		philo_data->is_thinking = TRUE;
	}
}

int	check_death(t_data *data, t_philo *philo_data)
{
	if ((gettime() - philo_data->last_eaten) > data->time_to_die)
	{
		ahfucksomeonedied(data, philo_data);
		return (1);
	}
	return (0);
}

void	tryeat(t_data *data, t_philo *philo_data)
{
	// get fork
	if (philo_data->id != philo_data->next_id)
	{
		pthread_mutex_lock(&data->take_fork);
		if (data->forks[philo_data->id - 1] == RETURNED && data->forks[philo_data->next_id - 1] == RETURNED)
		{
			data->forks[philo_data->id - 1] = TAKEN;
			printf("%ld %d has taken a fork\n", (gettime() - philo_data->start_time) / 1000, philo_data->id);
			data->forks[philo_data->next_id - 1] = TAKEN;
			printf("%ld %d has taken a fork\n", (gettime() - philo_data->start_time) / 1000, philo_data->id);
			philo_data->can_eat = TRUE;
		}
		pthread_mutex_unlock(&data->take_fork);
	}

	if (philo_data->can_eat && !check_death(data, philo_data))
	{
		philo_data->is_thinking = FALSE;
		philoeat(data, philo_data);

		// return fork
		data->forks[philo_data->id - 1] = RETURNED;
		data->forks[philo_data->next_id - 1] = RETURNED;
		philo_data->can_eat = FALSE;

		philosleep(data, philo_data);
	}
	else
		philothink(data, philo_data);
}

void	philo(void *arg)
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
	if (philo_data.id % 2)
	{
		philothink(data, &philo_data);
		usleep(data->time_to_sleep / 2);
	}
	while (!data->someone_died)
	{
		if (data->someone_died)
			break;
		tryeat(data, &philo_data);
	} 
}

bool	*init_forks(int n_philo)
{
	bool	*fork_table;
	int		i;

	fork_table = malloc (sizeof(bool) * n_philo);
	i = 0; 
	while (i < n_philo)
	{
		fork_table[i] = RETURNED;
		i++;
	}
	return (fork_table);
}

void	init_data(t_data *data, int	n_philo, int time_to_die, int time_to_eat, int time_to_sleep)
{
	data->id = 0;
	data->n_philo = n_philo;
	data->time_to_die = time_to_die;
	data->time_to_sleep = time_to_sleep;
	data->time_to_eat = time_to_eat;
	data->forks = init_forks(n_philo);
	data->someone_died = FALSE;
	data->start_sim = FALSE;
	data->philo_id = malloc ((sizeof(pthread_t) * n_philo));
	pthread_mutex_init(&data->take_fork, NULL);
	pthread_mutex_init(&data->return_fork, NULL);
	pthread_mutex_init(&data->died_lock, NULL);
}

int	main(int ac, char **av)
{
	int	n_philo = 3;
	int	time_to_die = 410;
	int	time_to_eat = 200;
	int	time_to_sleep = 200;
	t_data	data;
	int	i;

	time_to_die *= 1000;
	time_to_eat *= 1000;
	time_to_sleep *= 1000;
	init_data(&data, n_philo, time_to_die, time_to_eat, time_to_sleep);
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
}