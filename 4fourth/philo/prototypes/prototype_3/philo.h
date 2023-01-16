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
	pthread_mutex_t	write_data;
	pthread_mutex_t	death;
} t_data;

typedef	struct s_philo
{
	int			id;
	long int	start_time;
	long int	last_eaten;
	t_data		*data;

	int			forks;
	status		is_eating;
	status		is_sleeping;
	status		is_thinking;

	pthread_mutex_t	*r_hand;
	pthread_mutex_t	*l_hand;

	pthread_t	death_thread;
	pthread_t	main_thread;
	pthread_t	check_thread;
} t_philo;

long int	gettime();
void		print_timestamp(t_philo *philo_data, char *msg);
int			ft_atoi(const char *str);
int		str_len(char *msg);

#endif