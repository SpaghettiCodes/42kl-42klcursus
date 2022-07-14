#include "ft_printf.h"

void		ft_put_ptrprefix(void)
{
	write(1, "0x", 2);
}

int		ft_place_preci_ptr(properties *flag, int digits)
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

	ptraddr = (uintptr_t)va_arg(ptr, void *);
	if (flag->preci == 0 && !ptraddr)
	{
		printed = 2;
		if (flag->l_aligned != 1 && flag->width != -1)
			printed += ft_int_width_handler(flag, printed);
		ft_put_ptrprefix();
		if (flag->l_aligned)
			printed += ft_print_l_aligned(flag, 'd', printed);
		return (printed);
	}
	printed = ft_count_ptraddr(ptraddr);
	if (flag->preci > printed)
		printed = flag->preci;
	printed += 2;
	if (!flag->place_space)
		ft_put_ptrprefix();
	if (flag->l_aligned != 1 && flag->width != -1)
		printed += ft_int_width_handler(flag, (printed));
	if (flag->place_space)
		ft_put_ptrprefix();
	ft_place_preci_ptr(flag, ft_count_ptraddr(ptraddr));
	base = "0123456789abcdef";
	ft_put_ptraddr(ptraddr, base);
	if (flag->l_aligned)
		printed += ft_print_l_aligned(flag, 'd', printed);
	return (printed);
}

int	ft_count_ptraddr(uintptr_t ptraddr)
{
	int	printed;

	printed = 0;
	while (ptraddr >= 16 && ++printed)
		ptraddr /= 16;
	printed++;
	return (printed);
}

void	ft_put_ptraddr(uintptr_t n, char *base16)
{
	if (n >= 16)
		ft_put_ptraddr((n / 16), base16);
	ft_put_char(base16[n % 16]);
}
