#include "ft_printf.h"

void	ft_reset_flag(properties *flag)
{
	flag->type = '\0';
	flag->prefix = 0;
	flag->l_aligned = 0;
	flag->sign = 0;
	flag->place_space_front = 0;
	flag->width = -1;
	flag->place_space = 0;
	flag->place_zero = 0;
	flag->preci = -1;
}

properties	*ft_initialize_flag()
{
	properties *flag;

	flag = (properties *) malloc (sizeof(properties));
	ft_reset_flag(flag);
	return (flag);
}

int	print_flag(properties *flag, va_list ptr, int *printed)
{
	int	initial;
	int	added;

	added = ft_convertion(flag, ptr);
	if (added == -1)
		return (0);
	*printed = *printed + added;
	return (1);
}

int	format_handler(properties *flag, char *c, va_list ptr, int *printed)
{
	int	i;
	int	initial;

	i = 0;
	initial = *printed;
	printf("\ninitial = %d\n", initial);
	printf("\ni = %d (%c)\n", initial, c[i]);
	i++;
	printf("\ni = %d (%c)\n", initial, c[i]);
	while (check_flag(flag, c[i]))
	{
		i++;
	}
	printf("\ni = %d (%c)\n", initial, c[i]);
	if (check_width(flag, c[i]) > 0)
	{
		printf("\ncheck_width = %d\n" , check_width(flag, c[i]));
		flag->width = ft_atoi(&c[i]);
		printf("\nflag->width: %d\n", flag->width);
		while(c[i] >= '0' && c[i] <= '9')
			i++;
	}
	printf("\ni = %d (%c)\n", initial, c[i]);
	if (c[i] == '.')
	{
		i++;
		flag->preci = ft_atoi(&c[i]);
		while(c[i] >= '0' && c[i] <= '9')
			i++;
	}
	printf("\ni = %d (%c)\n", initial, c[i]);
	if(checktype(flag, c[i]));
		if(print_flag(flag, ptr, printed))
			return (i);
	return (0);
}

// follows THIS FUCKING ORDER
int	check_flag(properties *flag, char c)
{
	if (c == '-')
	{
		flag->place_space = 1;
		flag->l_aligned = 1;
	}
	else if (c == '+')
	{
		flag->place_space_front = 0;
		flag->sign = 1;
	}
	else if (c == ' ')
	{
		if (!flag->sign)
			flag->place_space_front = 1;
	}
	else if (c == '0')
	{
		flag->place_zero = 1;
	}
	else if (c == '#')
	{
		flag->prefix = 1;
	}
	else
		return (0);
	return (1);
	//not sure
}

int	check_width(properties *flag, char c)
{
	if (c == '*')
	{
		flag->width = -2;
		return (-1);
	}
	else if (c >= '0' && c <= '9')
	{
		if (!flag->place_zero)
			flag->place_space = 1;
	}
	else
	{
		return (0);
	}
	return (1);
}

int	checktype(properties *flag, char c)
{
	char *conversion;
	int		i;

	conversion = "cspdiuxX%";
	i = -1;
	while (conversion[++i] != c)
		if (conversion[i] == '\0')
			return (0);
	flag->type = conversion[i];
	return (1);
}

