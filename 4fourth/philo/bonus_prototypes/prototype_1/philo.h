#ifndef PHILO_H
#define PHILO_H

#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>

#define TRUE 1
#define FALSE 0
typedef	unsigned char status;

typedef struct s_data
{
	pid_t			*philo_childid;
	int				n_philo;

	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				start_sim;
	
	int				eat_count;

	sem_t			*forks;
	sem_t			*start;
	sem_t			*write;
	sem_t			*end;
	sem_t			*full;
} t_data;

typedef	struct s_philo
{
	t_data		*data;
	int			id;
	long int	start_time;
	long int	last_eaten;
	int			forks;

	status		is_eating;
	status		is_writing;
} t_philo;

long int	gettime();

void	print_timestamp(t_data *data, t_philo *philo_data, char *msg);
int			ft_atoi(const char *str);
int			str_len(char *msg);

void	philoeat(t_philo *philo, t_data *data);

void	philosleep(t_philo *philo,  t_data *data);

void	philothink(t_philo *philo, t_data *data);

void	get_fork(t_philo *philo, t_data *data);

void	philo_action(t_philo *philo, t_data *data);

#endif