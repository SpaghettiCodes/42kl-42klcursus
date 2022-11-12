#include "ft_printf.h"

int	ft_count_ptraddr(void *ptr)
{
	int	printed;
	uintptr_t ptraddr;

	write(1, "0x", 2);
	printed = 2;
	if (ptr == NULL && ++printed)
		write (1, "0", 1);
	else
	{
		ptraddr = (uintptr_t)ptr;
		while (ptraddr >= 16 && ++printed)
			ptraddr /= 16;
		printed++;
		ptraddr = (uintptr_t)ptr;
		ft_put_ptraddr(ptraddr, "0123456789abcdef");
	}
	return (printed);
}

void	ft_put_ptraddr(uintptr_t n, char *base16)
{
	if (n >= 10)
		ft_put_ptraddr((n / 16), base16);
	ft_put_char(base16[n % 16]);
}
