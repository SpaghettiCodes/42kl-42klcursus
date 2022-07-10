#include "ft_printf.h"

int	ft_char_handler(properties *flag, va_list ptr)
{
	int	printed;

	printed = 0;

	if (flag->type == 's')
		printed += ft_put_line(va_arg(ptr, char *), flag);
	else if (flag->type == 'c')
	{
		if (flag->l_aligned != 1 && flag->width != -1)
			printed += ft_width_handler(flag, 's', 1);
		printed += ft_put_char(va_arg(ptr, int));
	}
	if (flag->l_aligned)
		printed += ft_print_l_aligned(flag, 's', printed);
	return (printed);
}
