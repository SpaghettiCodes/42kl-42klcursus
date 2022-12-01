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
typedef	unsigned char bool;

typedef	struct s_philo
{
	int			id;
	int			next_id;
	long int	start_time;
	long int	last_eaten;
	bool		can_eat;
	bool		is_thinking;
	pthread_t	death_thread;
	pthread_t	main_thread;
} t_philo;

typedef struct s_data
{
	int				id;
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				*eat_count;
	long int		start_time;
	pthread_t		*philo_id;

	bool			start_sim;
	bool			someone_died;
	pthread_mutex_t	*forks;
	pthread_mutex_t	pick_fork;
} t_data;

typedef	struct s_arg
{
	t_philo	*philo_data;
	t_data	*data;	
} t_arg;

#endif