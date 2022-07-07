#include "ft_printf.h"

// easy, until you try to do flags

int ft_printf(const char *str, ...)
{
	int	i;
	int	printed;
	int	check;
	va_list ptr;

	i = -1;
	printed = 0;
	va_start(ptr, str);
	while (str[++i])
	{
		if (str[i] != '%')
			printed += ft_put_char(str[i]);
		else
		{
			check = ft_convertion(&str[i+1], ptr);
			if (check == -1)
			{
				printed += ft_put_char('%');
				continue;
			}
			va_arg(ptr, void *);
			printed += check;
			i++;
		}
	}
	return (printed);
}
