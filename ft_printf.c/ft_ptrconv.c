#include "ft_printf.h"

int		ft_place_preci_ptr(properties *flag, va_list ptr, int digits)
{
	int	i;

	i = 0;
	while (i < (flag->preci - digits) && ++i)
			ft_put_char('0');
	return (i);
}

int		ft_ptr_handler(properties* flag, va_list ptr)
{
	int		printed;
	char	*base;
	uintptr_t	ptraddr;

	printed = 0;
	ptraddr = (uintptr_t)va_arg(ptr, void *);
	printed += ft_count_ptraddr(ptraddr);
	if (flag->width != -1)
		printed += ft_width_handler(flag, 'd', printed);
	if (flag->prefix)
		ft_base16_putprefix(flag);
	printed += ft_place_preci_ptr(flag, ptr, printed);
	if (flag->type == 'p')
		base = "0123456789abcdef";
	ft_put_ptraddr(ptraddr, base);
	return (printed);
}


int	ft_count_ptraddr(uintptr_t ptraddr)
{
	int	printed;

	printed = 2;
	while (ptraddr >= 16 && ++printed)
		ptraddr /= 16;
	printed++;
	return (printed);
}

void	ft_put_ptraddr(uintptr_t n, char *base16)
{
	if (n >= 10)
		ft_put_ptraddr((n / 16), base16);
	ft_put_char(base16[n % 16]);
}
