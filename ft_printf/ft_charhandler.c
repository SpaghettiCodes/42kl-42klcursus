#include "ft_printf.h"

int		ft_char_width_handler(properties* flag, int printed)
{
	int	i;

	i = 0;
	if (flag->preci != -1 && flag->preci < printed)
		printed = flag->preci;
	while (i < (flag->width - printed) && ++i)
	{
		if (flag->place_zero)
			ft_put_char('0');
		else if (flag->place_space)
			ft_put_char(' ');
	}
	return (i);
}

int	ft_char_handler(properties *flag, va_list ptr)
{
	int	printed;

	printed = 0;

	if (flag->type == 's')
	{
		printed += ft_put_line(va_arg(ptr, char *), flag);
	}
	else if (flag->type == 'c')
	{
		if (!flag->l_aligned && flag->width != -1)
			printed += ft_char_width_handler(flag, 1);
		printed += ft_put_char(va_arg(ptr, int));
	}
	if (flag->l_aligned)
		printed += ft_print_l_aligned(flag, 's', printed);
	return (printed);
}

int	ft_none_handler(properties *flag)
{
	int	printed;

	printed = 0;
	if (!flag->l_aligned && flag->width != -1)
		printed += ft_char_width_handler(flag, 1);
	printed += ft_put_char((int)flag->type);
	if (flag->l_aligned)
		printed += ft_print_l_aligned(flag, 's', printed);
	return (printed);
}