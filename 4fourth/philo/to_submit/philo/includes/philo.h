/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:39:44 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/30 17:19:15 by cshi-xia         ###   ########.fr       */
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

// defines

# define TRUE 1
# define FALSE 0

// m yes typedef

typedef unsigned char	t_status;

// structures

typedef struct s_philo
{
	int				id;
	long int		start_time;
	long int		last_eaten;

	int				forks;

	pthread_mutex_t	*r_hand;
	pthread_mutex_t	*l_hand;
}	t_philo;

typedef struct s_data
{
	int				id;
	int				n_philo;

	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;

	int				*eat_count;

	pthread_t		*philo_id;

	t_status		start_sim;
	t_status		error;

	t_philo			*philo;

	pthread_mutex_t	*forks;
	pthread_mutex_t	*death_check;
	pthread_mutex_t	*eat_check;

	pthread_mutex_t	check_status;
	pthread_mutex_t	read_data;
	pthread_mutex_t	write_data;
	pthread_mutex_t	death;
}	t_data;

// print timestamps

// get current time
long int		gettime(void);
// print the message in the format - [timestamp] [id] [msg]
void			print_timestamp(t_data *data, t_philo *philo_data, char *msg);

// atoi

// converts char to int
int				ft_atoi(const char *str);
// gets str length
int				str_len(char *msg);

// philo action

// philosopher eats
void			philoeat(t_philo *philo_data, t_data *data);
// philosopher sleeps
void			philosleep(t_philo *philo_data, t_data *data);
// philosopher thinks
void			philothink(t_philo *philo_data, t_data *data);
// philosopher tries to get fork
void			get_fork(t_philo *philo_data, t_data *data);
// controls philospher actions
void			philo_action(t_philo *philo_data, t_data *data);

// condition checkers

// condition checker
int				check_cond(t_data *data);
// checks if [eat count] is fulfilled for each philospher
int				check_count(t_data *data);
// check if philosopher is dead for every death time
int				philodeath(t_data *data);

// thread functions

// main function for mainthread
int				philo(t_data *data);
// run the simulation
void			run_sim(t_philo *philo_data, t_data *data);
// releases mutex lock for dead philo (program doesnt hang)
void			release_locks(t_philo *philo_data);

// initialize stuff

// initialize the forks (table of mutexes)
pthread_mutex_t	*init_forks(int n_philo);
// initialize the philo structure
void			philo_init(t_philo	*philo_data, t_data	*data, int id);
// initalize data struct based on argc and argv
int				get_data(t_data *data, int ac, char **av);
// initalize the eat count table
int				*init_eatcount(int n_philo, int eat_count);

// error

// error printing
int				eprint(char *str);

// wait for sim start
int				waitforsignal(t_data *data);

int				init_mutex(pthread_mutex_t *to_init);

void			free_mutex_table(pthread_mutex_t *table, int count);

void			free_alldata(t_data *data, char mutex_inited);

#endif