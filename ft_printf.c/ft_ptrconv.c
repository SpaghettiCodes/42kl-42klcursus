#include "ft_printf.h"

int		ft_put_ptrprefix(properties *flag)
{
	write(1, "0x", 2);
	return (2);
}

int		ft_ptrwidth_handler(properties* flag, int printed)
{
	int	i;

	i = 0;
	while (i < (flag->width - printed) && ++i)
	{
		if (flag->place_zero)
			ft_put_char('z');
		else if (flag->place_space)
			ft_put_char('s');
	}
	return (i);
}

int		ft_place_preci_ptr(properties *flag, va_list ptr, int digits)
{
	int	i;

	i = 0;
	while (i < (flag->preci - digits) && ++i)
			ft_put_char('p');
	return (i);
}

int		ft_ptr_handler(properties* flag, va_list ptr)
{
	int		printed;
	char	*base;
	uintptr_t	ptraddr;

	ptraddr = (uintptr_t)va_arg(ptr, void *);
	printed = ft_count_ptraddr(ptraddr);
	printed += ft_put_ptrprefix(flag);
	if (flag->width != -1)
		printed += ft_ptrwidth_handler(flag, printed);
	printed += ft_place_preci_ptr(flag, ptr, ft_count_ptraddr(ptraddr));
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
