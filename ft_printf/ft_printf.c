#include "ft_printf.h"

int	met_percent(const char *str, va_list ptr, int *printed)
{
	properties *flag;
	int			i;
	int			initial;

	i = 0;
	flag = ft_initialize_flag();
	initial = i;
	i += format_handler(flag, (char *)&str[i], ptr, printed); // note: you will be at the conversion letter after this
	free(flag);
	return (i);
}

int ft_printf(const char *str, ...)
{
	int	i;
	int	check;
	int	printed;
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
			check = met_percent(&str[i], ptr, &printed);
			if (check == -1)
			{
				printed += ft_put_char(str[i]);
				continue ;
			}
			i += check;
		}
	}
	return (printed);
}
