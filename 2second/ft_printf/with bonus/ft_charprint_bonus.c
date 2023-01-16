#include "ft_printf_bonus.h"

int	ft_put_null(t_properties *flag)
{
	if (flag->preci > 6)
		flag->preci = 6;
	write(1, "(null)", flag->preci);
	return (flag->preci);
}

int	ft_put_char(int a)
{
	write(1, &a, 1);
	return (1);
}

int	ft_strlen(char *a)
{
	int	i;

	i = 0;
	if (!a)
		return (6);
	while (a[i])
		i++;
	return (i);
}
