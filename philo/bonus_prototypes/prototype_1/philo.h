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

	status			start_sim;

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

} t_philo;

long int	gettime();
void		print_timestamp(t_philo *philo_data, char *msg);
int			ft_atoi(const char *str);
int			str_len(char *msg);

#endif