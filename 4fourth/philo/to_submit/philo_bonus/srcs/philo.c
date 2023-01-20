/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:16:29 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/20 14:34:35 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	gettime()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000000) + time.tv_usec);
}

int	eprint(char	*str)
{
	return (write(2, str, str_len(str)));
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

void	check_death(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	while (data->start_sim)
	{
		usleep(data->time_to_die);
		if ((gettime() - philo->last_eaten) > data->time_to_die)
		{
			print_timestamp(data, philo, "died\n");
			sem_post(data->end);
			sem_wait(data->start);
			return ;
		}
	}
}

void	run_sim(t_philo *philo)
{
	t_data *data;
	pthread_t death_thread;

	data = philo->data;
	sem_wait(data->start);
	data->start_sim = TRUE;
	philo->start_time = gettime();
	philo->last_eaten = philo->start_time;
	pthread_create(&death_thread, 0, (void *)check_death, philo);
	pthread_detach(death_thread);
	if (philo->id > (data->n_philo / 2))
	{
		philothink(philo, data);
		usleep(data->time_to_eat / 2);
	}
	while (data->start_sim)
		philo_action(philo, data);
}

void	philo(int id, t_data *data)
{
	t_philo		philo;

	++id;
	init_philo(&philo, data, id);
	run_sim(&philo);
}

void	killallchild(t_data data)
{
	int	i;

	i = 0;
	while (i < data.n_philo)
	{
		kill(data.philo_childid[i], SIGTERM);
		sem_post(data.full);
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
		++done_eating;
	}
	sem_post(data->end);
	return ;
}

void	death_check(t_data *data, pthread_t *checker)
{
	sem_wait(data->end);
	killallchild(*data);
	pthread_join(*checker, NULL);
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
			++i;
	}
	i = -1;
	while (++i < data.n_philo)
		sem_post(data.start);
	pthread_create(&checker, NULL, (void *)full_check, &data);
	death_check(&data, &checker);
}
