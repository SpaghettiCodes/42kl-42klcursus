#include "pushswap.h"

int	error(t_stack *stack)
{
	write(1, "Error\n", 7);
	if (stack)
		deleteall(stack);
	exit(69);
	return (420);
}

static int	ft_isspace(char c)
{
	return ((c == 32) || (c >= 9 && c <= 13));
}

static int	overflow(int result, int neg, char nextnum)
{
	if (result <= 214748364)
	{
		if (result == 214748364)
		{
			if ((nextnum <= '7' && neg == 1) || (nextnum <= '8' && neg == -1))
				return (1);
		}
		else
			return (1);
	}
	return (0);
}

int	ft_atoi(const char *str, t_stack *stack)
{
	int	result;
	int	negative;
	int	i;

	i = 0;
	result = 0;
	negative = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' && ++i)
		negative = -1;
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (error(stack));
		if (!overflow(result, negative, str[i]))
			return (error(stack));
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * negative);
}

int	fill(int *a, char **av, int ac)
{
	int	i;

	i = -1;
	ac--;
	while (++i < ac)
		a[i] = ft_atoi(av[i], a);
	return (1);
}

int	checkdup(int *a, int size_a)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size_a)
	{
		j = i;
		while (++j < size_a)
		{
			if (a[i] == a[j])
				return (error(a));
		}
	}
	return (1);
}

int	pushswap(int *a, int size_a, int b, int size_b)
{
	int	*dup;
	int	dupsize;

	dupsize = size_a;
	dup = int_dup(a, size_a);
}

int	main(int ac, char **av)
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;

	if (ac == 1)
		return ;
	a = (int *) malloc (sizeof(ac - 1));
	size_a = ac - 1;
	fill(a, av, ac);
	checkdup(a, size_a);
	b = (int *) malloc (sizeof(ac - 1));
	size_b = 0;
	pushswap(a, size_a, b, size_b); // this would be the sorting algo
	free(a);
	free(b);
	return (1);
}
