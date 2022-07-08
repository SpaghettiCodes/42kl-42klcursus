#include "ft_printf.h"

int	ft_char_handler(properties *flag, va_list ptr)
{
	int		printed;

	printed = 0;

	if (flag->type == 's')
		printed += ft_put_line(va_arg(ptr, char *), flag->preci);
	else if (flag->type == 'c')
		printed += ft_put_char(va_arg(ptr, int));
	else
		return (ft_int_handler(flag, ptr));
	if (flag->l_aligned)
		printed += ft_print_l_aligned(flag, 's', printed);
	return (printed);
}

int	ft_print_l_aligned(properties *flag, int type, int printed)
{
	int	i;

	i = 0;
	if (type == 's')
		while (i < ((flag->width) - printed) && ++i)
			ft_put_char(' ');
	if (type == 'd')
	{
		while (i < ((flag->width) - printed) && ++i)
		{
			if (flag->place_space)
				ft_put_char(' ');
		}
	}
	return (i);
}

int	ft_put_null()
{
	write(1, "(null)", 6);
	return (6);
}

int	ft_put_char(int a)
{
	write(1, &a, 1);
	return (1);
}

int	ft_strlen(char *a)
{
	int	i;

	i = -1;
	while (a[++i])
		continue;
	return (i);
}

int	ft_put_line(char *a, int preci)
{
	int	i;

	i = -1;
	if (preci == -1)
		preci = ft_strlen(a);
	if (!a)
		return (ft_put_null());
	while (a[++i] && i < preci)
		write(1, &a[i], 1);
	return (i);
}
