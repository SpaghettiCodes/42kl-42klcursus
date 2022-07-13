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

int	ft_strlen(char *a)
{
	int	i;

	i = -1;
	while (a[++i])
		continue;
	return (i);
}

int	ft_put_line(char *a, properties *flag)
{
	int	i;
	int	printed;

	printed = 0;
	if (flag->l_aligned != 1 && flag->width != -1)
		printed += ft_width_handler(flag, 's' , ft_strlen(a));
	i = -1;
	if (flag->preci == -1)
		flag->preci = ft_strlen(a);
	if (!a)
		return (ft_put_null());
	while (a[++i] && i < flag->preci)
		printed += ft_put_char(a[i]);
	return (printed);
}
