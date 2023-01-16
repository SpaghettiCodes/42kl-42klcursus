/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:29:07 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/17 18:49:46 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_place_preci_ptr(t_properties *flag, int digits)
{
	int	i;

	i = 0;
	while (i < (flag->preci - digits) && ++i)
		ft_put_char('0');
	return (i);
}

int	ptr_null(t_properties *flag)
{
	int	printed;

	printed = 2;
	if (flag->l_aligned != 1 && flag->width != -1)
		printed += ft_int_width_handler(flag, printed);
	write(1, "0x", 2);
	if (flag->l_aligned && flag->width != -1)
		printed += ft_print_l_aligned(flag, printed);
	return (printed);
}

int	ft_ptr_handler(t_properties *flag, va_list ptr)
{
	int			printed;
	uintptr_t	ptraddr;

	ptraddr = (uintptr_t)va_arg(ptr, void *);
	if (flag->preci == 0 && !ptraddr)
		return (ptr_null(flag));
	printed = ft_count_ptraddr(ptraddr);
	if (flag->preci > printed)
		printed = flag->preci;
	printed += 2;
	if (!flag->place_space)
		write(1, "0x", 2);
	if (flag->l_aligned != 1 && flag->width != -1)
		printed += ft_int_width_handler(flag, (printed));
	if (flag->place_space)
		write(1, "0x", 2);
	ft_place_preci_ptr(flag, ft_count_ptraddr(ptraddr));
	ft_put_ptraddr(ptraddr, "0123456789abcdef");
	if (flag->l_aligned && flag->width != -1)
		printed += ft_print_l_aligned(flag, printed);
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
