#include "ft_printf.h"

int	ft_place_preci(properties *flag, int digits)
{
	int	i;

	i = 0;
	while (i < (flag->preci - digits) && ++i)
			ft_put_char('0');
	return (i);
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

int		ft_base16_putprefix(properties* flag)
{
	if (flag->type == 'x')
		write(1, "0x", 2);
	else if (flag->type == 'X')
		write(1, "0X", 2);
	return (2);
}
