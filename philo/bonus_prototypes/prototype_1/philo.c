#include "philo.h"

long int	gettime()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000000) + time.tv_usec);
}

int	eprint(char	*str)
{
	return(write(2, str, str_len(str)));
}

int	init_data(t_data *data, int ac, char **av)
{
	int	eat_count;

	data->id = 0;
	data->n_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]) * 1000;
	data->time_to_eat = ft_atoi(av[3]) * 1000;
	data->time_to_sleep = ft_atoi(av[4]) * 1000;
	if (ac == 6)
	{
		eat_count = ft_atoi(av[5]);
		if (eat_count <= 0)
			return (eprint("Invalid Eat Count\n"));
	}
	else
		eat_count = -1;

	data->start_sim = FALSE;

	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	int	i;

	if (ac < 5)
		return (eprint("Not enough arguments\n"));
	else if (ac > 6)
		return (eprint("Too much arguments\n"));

	if (init_data(&data, ac, av))
		return (-1);
}