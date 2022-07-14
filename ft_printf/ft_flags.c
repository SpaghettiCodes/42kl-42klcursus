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
	int	added;

	added = ft_convertion(flag, ptr);
	*printed = *printed + added;
	return (1);
}

int	format_handler(properties *flag, char *c, va_list ptr, int *printed)
{
	int	i;

	i = 1;
	while (check_flag(flag, c[i]))
		i++;
	if (check_width(flag, c[i]) != 0)
	{
		if (flag->width == -1)
		{
			flag->width = ft_atoi(&c[i]);
			while((c[i] >= '0' &&  c[i] <= '9'))
				i++;
		}
		else if (flag->width == -2 && c[i] == '*')
			i++;
	}
	if (c[i] == '.' && ++i)
	{
		flag->place_space = 1;
		flag->place_zero = 0;
		if (c[i] == '*' && ++i)
			flag->preci = -2;
		else
		{
			flag->preci = ft_atoi(&c[i]);
			while ((c[i] >= '0' &&  c[i] <= '9'))
				i++;
		}
	}
	flag->type = c[i];
	if (flag->type == '\0')
		return (-1);
	print_flag(flag, ptr, printed);
	return (i);
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
		flag->place_zero = 1;
	else if (c == '#')
		flag->prefix = 1;
	else
		return (0);
	return (1);
}

int	check_width(properties *flag, char c)
{
	if ((c >= '0' && c <= '9') || c == '*')
	{
		if (!flag->place_zero)
			flag->place_space = 1;
		if (c == '*')
			flag->width = -2;
	}
	else
		return (0);
	return (1);
}
