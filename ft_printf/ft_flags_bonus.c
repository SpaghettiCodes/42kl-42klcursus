#include "ft_printf_bonus.h"

void	ft_reset_flag(t_properties *flag)
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

t_properties	*ft_initialize_flag()
{
	t_properties *flag;

	flag = (t_properties *) malloc (sizeof(t_properties));
	ft_reset_flag(flag);
	return (flag);
}

int	print_flag(t_properties *flag, va_list ptr, int *printed)
{
	*printed = *printed + ft_convertion(flag, ptr);
	return (1);
}

int	check_preci(t_properties *flag, char *format)
{
	int	i;

	i = 0;
	flag->place_space = 1;
	flag->place_zero = 0;
	if (format[i] == '*' && ++i)
		flag->preci = -2;
	else
	{
		flag->preci = ft_atoi(&format[i]);
		while ((format[i] >= '0' && format[i] <= '9'))
			i++;
	}
	return (i);
}

int	format_handler(t_properties *flag, char *c, va_list ptr, int *printed)
{
	int	i;

	i = 1;
	while (check_flag(flag, c[i]))
		i++;
	if (check_width(flag, c[i]) != 0)
	{
		if (flag->width == -2)
			i++;
		else
		{
			flag->width = ft_atoi(&c[i]);
			while((c[i] >= '0' &&  c[i] <= '9'))
				i++;
		}
	}
	if (c[i] == '.' && ++i)
		i += check_preci(flag, &c[i]);
	flag->type = c[i];
	if (flag->type == '\0')
		return (-1);
	print_flag(flag, ptr, printed);
	return (i);
}

int	check_flag(t_properties *flag, char c)
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

int	check_width(t_properties *flag, char c)
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
