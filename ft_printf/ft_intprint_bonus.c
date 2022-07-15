#include "ft_printf_bonus.h"

int	ft_count_uint(unsigned int nbr, int base)
{
	int				digit;
	unsigned int	n;

	digit = 0;
	n = nbr;
	while (n >= (unsigned int)base && ++digit)
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
		return (ft_count_uint((unsigned int)(n * -1), 10));
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
		write(1, "2", 1);
		ft_put_int(147483648);
		return ;
	}
	if (n < 0)
	{
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
