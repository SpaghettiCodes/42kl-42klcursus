#include "ft_printf.h"

// easy, until you try to do flags

int ft_printf(const char *str, ...)
{
	int	i;
	int	printed;
	int	initial;
	va_list ptr;
	properties *flag;

	i = -1;
	printed = 0;
	va_start(ptr, str);
	while (str[++i])
	{
		if (str[i] != '%')
			printed += ft_put_char(str[i]);
		else
		{
			flag = ft_initialize_flag();
			initial = i;
			i += format_handler(flag, &str[i], ptr, &printed);
			free(flag);
			if (i == initial)
				printed += ft_put_char('%');
		}
	}
	return (printed);
}
