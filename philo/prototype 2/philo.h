#ifndef PHILO_H
#define PHILO_H

#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
typedef	unsigned char status;

typedef	struct s_philo
{
	int			id;
	int			next_id;
	long int	start_time;
	long int	last_eaten;
	status		can_eat;
	status		is_thinking;
	pthread_t	death_thread;
	pthread_t	main_thread;
	pthread_t	check_thread;
} t_philo;

typedef struct s_data
{
	int				id;
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				*eat_count;
	pthread_t		*philo_id;

	status			start_sim;
	pthread_mutex_t	*forks;
	pthread_mutex_t	pick_fork;
	pthread_mutex_t	write_data;
} t_data;

typedef	struct s_arg
{
	t_philo	*philo_data;
	t_data	*data;
} t_arg;

long int	gettime();
void	print_timestamp(t_data *data, t_philo *philo_data, char *msg);

#endif