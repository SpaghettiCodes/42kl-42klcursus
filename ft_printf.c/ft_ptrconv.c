#include "ft_printf.h"

int		ft_ptr_handler(properties* flag, va_list ptr)
{
	int		printed;
	char	*base;
	uintptr_t	ptraddr;

	printed = 0;
	ptraddr = (uintptr_t)va_arg(ptr, void *);
	printed += ft_count_ptraddr(ptraddr);
	if (flag->prefix)
		printed += ft_base16_putprefix(flag);
	if (flag->place_space_front)
		printed += ft_put_char(' ');
	if (flag->l_aligned != 1 && flag->width != -1)
		printed += ft_width_handler(flag, 'd', printed);
	if (flag->type == 'p')
		base = "0123456789abcdef";
	ft_put_ptraddr(ptraddr, base);
	if (flag->l_aligned)
		printed += ft_print_l_aligned(flag, 'd', printed);
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
