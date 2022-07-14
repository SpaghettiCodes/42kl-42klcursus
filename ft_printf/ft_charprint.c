#include "ft_printf.h"

int	ft_put_null(properties *flag)
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

	i = -1;
	if (!a)
		return (6);
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
		printed += ft_char_width_handler(flag, ft_strlen(a));
	i = -1;
	if (flag->preci == -1)
		flag->preci = ft_strlen(a);
	if (!a)
	{
		printed += ft_put_null(flag);
		return (printed);
	}
	while (a[++i] && i < flag->preci)
		printed += ft_put_char(a[i]);
	return (printed);
}
