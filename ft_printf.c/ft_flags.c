#include "ft_printf.h"

void	ft_reset_flag(properties *flag)
{
	flag->type = '\0';
	flag->convrt = 0;
	flag->l_aligned = 0;
	flag->sign = 1;
	flag->place_space_front = 0;
	flag->width = INT_MIN;
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

void	print_flag(properties *flag, va_list ptr, int *printed)
{
	*printed = *printed + ft_convertion(flag, ptr);
}

int	format_handler(properties *flag, char *c, va_list ptr, int *printed)
{
	int	i;

	i = 0;
	while (check_flag(flag, c[i]))
		i++;
	while (check_width(flag, c[i]))
	{
		i++;
		flag->width = ft_atoi(c);
		while(c[i] >= '0' && c[i] <= '9')
			i++;
	}
	if (c[i] == '.')
	{
		i++;
		flag->preci = ft_atoi(c);
		while(c[i] >= '0' && c[i] <= '9')
			i++;
	}
	if(checktype(flag, c));
		print_flag(flag, ptr, printed);
	return (i);
}

// follows THIS FUCKING ORDER
int	check_flag(properties *flag, char c)
{
	if (c == '-')
		flag->l_aligned = 1;
	if (c == '+')
	{
		flag->place_space_front = 0;
		flag->sign = 1;
	}
	if (c == ' ')
	{
		if (!flag->sign)
			flag->place_space_front = 1;
	}
	if (c == '#'){}
	else
		return (0);
	//not sure
}

// follow THIS FUCKING ORDER
int	check_width(properties *flag, char c)
{
	if (c == '0')
		flag->place_zero = 1;
	if (c == '*');
	else
		return (0);
	if (!flag->place_zero)
		flag->place_space = 1;
	return (1);
}

int	checktype(properties *flag, char c)
{
	char *conversion;
	int		i;

	conversion = "cspdiuxX%";
	i = -1;
	while (conversion[i] != c)
		if (conversion[i] == '\0')
			return (0);
	flag->type = conversion[i];
	return (1);
}

