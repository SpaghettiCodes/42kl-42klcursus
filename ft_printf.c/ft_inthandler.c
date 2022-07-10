#include "ft_printf.h"

int		ft_int_handler(properties* flag, va_list ptr)
{
	int printed;
	int	nbr;

	printed = 0;
	nbr = va_arg(ptr, int);
	printed += ft_count_int(nbr);
	if (flag->place_space_front)
		printed += ft_put_char(' ');
	if (flag->sign)
	{
		if (nbr > 0)
			printed += ft_put_char('+');
	}
	if (flag->l_aligned != 1 && flag->width != -1)
		printed += ft_width_handler(flag, 'd', (printed));
	printed += ft_place_preci(flag, ptr, ft_count_int(nbr));
	ft_put_int(nbr);
	if (flag->l_aligned)
		printed += ft_print_l_aligned(flag, 'd', printed);
	return (printed);
}

int		ft_uint_handler(properties* flag, va_list ptr)
{
	int printed;
	int	nbr;

	printed = 0;
	nbr = va_arg(ptr, unsigned int);
	printed = ft_count_uint(nbr, 10);
	if (flag->l_aligned != 1 && flag->width != -1)
		printed += ft_width_handler(flag, 'd', printed);
	printed += ft_place_preci(flag, ptr, ft_count_uint(nbr, 10));
	ft_put_unsigned_int(nbr);
	if (flag->l_aligned)
		printed += ft_print_l_aligned(flag, 'd', printed);
	return (printed);
}

int		ft_base16_handler(properties* flag, va_list ptr)
{
	int		printed;
	int		nbr;
	char	*base;

	printed = 0;
	nbr = va_arg(ptr, unsigned int);
	printed += ft_count_uint(nbr, 16);
	if (flag->prefix)
		printed += ft_base16_putprefix(flag);
	if (flag->place_space_front)
		printed += ft_put_char(' ');
	if (flag->l_aligned != 1 && flag->width != -1)
		printed += ft_width_handler(flag, 'd', printed);
	printed += ft_place_preci(flag, ptr, ft_count_uint(nbr, 16));
	if (flag->type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	ft_put_int_base16(nbr, base);
	if (flag->l_aligned)
		printed += ft_print_l_aligned(flag, 'd', printed);
	return (printed);
}
