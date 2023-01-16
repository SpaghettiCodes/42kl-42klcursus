#include <stdio.h>

int	error(int x)
{
	printf("error\n");
	return (x);
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
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
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
	if (str[i] == '\0')
		return (-1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (error(-1));
		if (overflow(result, negative, str[i]))
			return (error(-1));
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * negative);
}