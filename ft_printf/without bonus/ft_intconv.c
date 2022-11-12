#include "ft_printf.h"

int		ft_count_uint(unsigned int nbr, unsigned int base, char format)
{
	int				digit;
	unsigned int	n;

	digit = 0;
	n = nbr;
	while (n >= base && ++digit)
		n /= base;
	digit++;
	if (format == 'U')
		ft_put_unsigned_int(nbr);
	else if (format == 'X')
		ft_put_int_base16(nbr, "0123456789ABCDEF");
	else if (format == 'x')
		ft_put_int_base16(nbr, "0123456789abcdef");
	return (digit);
}

int		ft_count_int(int nbr)
{
	int	digit;
	int	n;

	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_count_uint((unsigned int)(n * -1), 10, 'U') + 1);
	}
	digit = 0;
	while (n >= 10 && ++digit)
		n /= 10;
	digit++;
	ft_put_int(nbr);
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
	if (n >= 10)
		ft_put_int(n / 10);
	ft_put_char((n % 10) + '0');
}

void	ft_put_int_base16(unsigned int n, char *base16)
{
	if (n >= 10)
		ft_put_int_base16((n / 16), base16);
	ft_put_char(base16[n % 16]);
}
