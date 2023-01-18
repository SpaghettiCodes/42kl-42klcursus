/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inthandler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:28:51 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/17 18:49:46 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int_null(t_properties *flag)
{
	int	printed;

	printed = 0;
	if (flag->l_aligned != 1 && flag->width != -1)
		printed += ft_int_width_handler(flag, printed);
	if (flag->l_aligned && flag->width != -1)
		printed += ft_print_l_aligned(flag, printed);
	return (printed);
}

int	expected_value(t_properties *flag, int nbr)
{
	int	printed;

	printed = ft_count_int(nbr);
	if (flag->preci > ft_count_int(nbr))
		printed = flag->preci;
	if (nbr < 0)
		printed++;
	return (printed);
}

int	ft_int_handler(t_properties *flag, va_list ptr)
{
	int	printed;
	int	nbr;

	nbr = va_arg(ptr, int);
	if (flag->preci == 0 && nbr == 0)
		return (ft_int_null(flag));
	printed = expected_value(flag, nbr);
	if (flag->place_space_front && nbr >= 0)
		printed += ft_put_char(' ');
	if (flag->sign && nbr >= 0)
		printed += ft_put_char('+');
	if (nbr < 0 && !flag->place_space)
		ft_put_char('-');
	if (flag->l_aligned != 1 && flag->width != -1)
		printed += ft_int_width_handler(flag, (printed));
	if (nbr < 0 && flag->place_space)
		ft_put_char('-');
	ft_place_preci(flag, ft_count_int(nbr));
	ft_put_int(nbr);
	if (flag->l_aligned && flag->width != -1)
		printed += ft_print_l_aligned(flag, printed);
	return (printed);
}

int	ft_uint_handler(t_properties *flag, va_list ptr)
{
	int	printed;
	int	nbr;

	nbr = va_arg(ptr, unsigned int);
	printed = ft_count_uint(nbr, 10);
	if (flag->preci == 0 && nbr == 0)
		return (ft_int_null(flag));
	if (flag->preci > printed)
		printed = flag->preci;
	if (flag->l_aligned != 1 && flag->width != -1)
		printed += ft_int_width_handler(flag, printed);
	ft_place_preci(flag, ft_count_uint(nbr, 10));
	ft_put_unsigned_int(nbr);
	if (flag->l_aligned)
		printed += ft_print_l_aligned(flag, printed);
	return (printed);
}

int	ft_base16_handler(t_properties *flag, va_list ptr)
{
	int	printed;
	int	nbr;

	nbr = va_arg(ptr, unsigned int);
	printed = ft_count_uint(nbr, 16);
	if (flag->preci == 0 && nbr == 0)
		return (ft_int_null(flag));
	if (flag->preci > printed)
		printed = flag->preci;
	if (flag->prefix && nbr != 0)
		printed += ft_base16_putprefix(flag);
	if (flag->l_aligned != 1 && flag->width != -1)
		printed += ft_int_width_handler(flag, printed);
	ft_place_preci(flag, ft_count_uint(nbr, 16));
	if (flag->type == 'x')
		ft_put_int_base16(nbr, "0123456789abcdef");
	else if (flag->type == 'X')
		ft_put_int_base16(nbr, "0123456789ABCDEF");
	if (flag->l_aligned)
		printed += ft_print_l_aligned(flag, printed);
	return (printed);
}
