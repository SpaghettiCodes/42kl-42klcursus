
#include "ft_printf.h"

int	ft_put_char(int a)
{
	char c = a;
	write(1, &c, 1);
	return (1);
}

int	ft_put_line(char *a)
{
	int	i;

	i = -1;
	while (a[++i])
		write(1, &a[i], 1);
	return (i);
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
		write(1, "-", 1);
		ft_put_char('2');
		ft_put_int(147483648);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		ft_put_int((n * -1));
		return ;
	}
	if (n >= 10)
		ft_put_int(n / 10);
	ft_put_char((n % 10) + '0');
}

void	ft_put_int_base16(unsigned int n, char *base16)
{
	if (n >= 10)
		ft_put_int_base16((n / 10), base16);
	ft_put_char(base16[n % 10]);
}
