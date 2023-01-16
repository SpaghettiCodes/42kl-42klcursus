#ifndef PHILO_H
#define PHILO_H

#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

// defines

#define TRUE 1
#define FALSE 0

// m yes typedef

typedef	unsigned char status;

// structures

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

// print timestamps

// get current time
long int		gettime();

// print the message in the format - [timestamp] [id] [msg]
void			print_timestamp(t_philo *philo_data, char *msg);

// atoi

// converts char to int
int				ft_atoi(const char *str);

// gets str length
int				str_len(char *msg);

// philo action

// philosopher eats
void			philoeat(t_philo *philo_data);

// philosopher sleeps
void			philosleep(t_philo *philo_data);

// philosopher thinks
void			philothink(t_philo *philo_data);

// philosopher tries to get fork
void			get_fork(t_philo *philo_data);

// controls philospher actions
void			philo_action(t_philo *philo_data);

// condition checkers

// checks if [eat count] is fulfilled for each philospher EVERY. TICK.
void			check_full(t_data *data);

// checks if [eat count] is fulfilled for each philospher
int				check_count(t_data *data);

// check if philosopher is dead for every death time
void			philodeath(t_philo *philo_data);

// thread functions

// main function for mainthread
int				philo(void *arg);

// create subthreads in mainthread
void			create_subthreads(t_philo *philo_data);

// join subthreads in mainthread
void			join_subthreads(t_philo *philo_data);

// run the simulation
void			run_sim(t_philo *philo_data);

// releases mutex lock for dead philo (program doesnt hang)
void			release_locks(t_philo *philo_data);

// initialize stuff

// initialize the forks (table of mutexes)
pthread_mutex_t	*init_forks(int n_philo);

// initialize the philo structure
void			philo_init(t_philo	*philo_data, t_data	*data);

// initalize data struct based on argc and argv
int				init_data(t_data *data, int ac, char **av);

// initalize the eat count table
int				*init_eatcount(int n_philo, int eat_count);

// error

// error printing
int				eprint(char *str);

#endif