/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:39:46 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/30 17:10:27 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <signal.h>

# define TRUE 1
# define FALSE 0

typedef unsigned char	t_status;
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
}	t_data;

typedef struct s_philo
{
	t_data		*data;
	int			id;
	long int	start_time;
	long int	last_eaten;
	int			forks;

	t_status	is_eating;
	t_status	is_writing;
}	t_philo;

long int	gettime(void);

void		print_timestamp(t_data *data, t_philo *philo_data, char *msg);
int			ft_atoi(const char *str);
int			str_len(char *msg);

void		philoeat(t_philo *philo, t_data *data);

void		philosleep(t_philo *philo, t_data *data);

void		philothink(t_philo *philo, t_data *data);

void		get_fork(t_philo *philo, t_data *data);

void		philo_action(t_philo *philo, t_data *data);

int			init_data(t_data *data, int ac, char **av);

void		init_philo(t_philo *philo, t_data *data, int id);

void		open_sem(t_data *data);

int			eprint(char *err_msg);

int			run_sim(t_philo *philo);

void		philo(int id, t_data *data);

void		full_check(t_data *data);

void		death_check(t_data *data, pthread_t *checker);

void		check_death(void *arg);

void		open_sem(t_data *data);

void		unlink_sems(void);

void		killallchild(t_data data);

void		freedata(t_data *data);

#endif