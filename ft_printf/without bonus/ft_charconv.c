#include "ft_printf.h"

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

int	ft_put_line(char *a)
{
	int	i;

	i = -1;
	if (!a)
		return (ft_put_null());
	while (a[++i])
		write(1, &a[i], 1);
	return (i);
}

int	ft_put_percent()
{
	return (ft_put_char('%'));
}
