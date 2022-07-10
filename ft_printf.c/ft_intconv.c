#include "ft_printf.h"

int		ft_width_handler(properties* flag, char format, int printed)
{
	int	i;

	i = 0;
	if (format == 's')
	{
		if (flag->preci != -1 && flag->preci < printed)
			printed = flag->preci;
		while (i < (flag->width - printed) && ++i)
				ft_put_char(' ');
	}
	else if (format == 'd')
	{
		if (flag->preci > printed)
			printed = flag->preci;
		while (i < (flag->width - printed) && ++i)
		{
			if (flag->place_zero)
				ft_put_char('0');
			else if (flag->place_space)
				ft_put_char(' ');
		}
	}
	return (i);
}

int		ft_place_preci(properties *flag, va_list ptr, int digits)
{
	int	i;

	i = 0;
	while (i < (flag->preci - digits) && ++i)
			ft_put_char('0');
	return (i);
}

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

int		ft_base16_putprefix(properties* flag)
{
	if (flag->type == 'x')
		write(1, "0x", 2);
	else if (flag->type == 'X')
		write(1, "0X", 2);
	return (2);
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

int	ft_count_uint(unsigned int nbr, int base)
{
	int				digit;
	unsigned int	n;

	digit = 0;
	n = nbr;
	while (n >= base && ++digit)
		n /= base;
	digit++;
	return (digit);
}

int	ft_count_int(int nbr)
{
	int	digit;
	int	n;

	n = nbr;
	if (n < 0)
		return (ft_count_uint((unsigned int)(n * -1), 10) + 1);
	digit = 0;
	while (n >= 10 && ++digit)
		n /= 10;
	digit++;
	return (digit);
}

void	ft_put_unsigned_int(unsigned int n)
{
	if (n >= 10)
		ft_put_unsigned_int(n / 10);
	ft_put_char((n % 10) + '0');
}

void	ft_put_int(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2", 2);
		ft_put_int(147483648);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		ft_put_int(n * -1);
		return ;
	}
	if (n >= 10)
		ft_put_int(n / 10);
	ft_put_char((n % 10) + '0');
}

void	ft_put_int_base16(unsigned int n, char *base16)
{
	if (n >= 16)
		ft_put_int_base16((n / 16), base16);
	ft_put_char(base16[n % 16]);
}
