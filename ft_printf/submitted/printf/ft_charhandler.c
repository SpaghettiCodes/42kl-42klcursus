/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charhandler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:28:24 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/17 18:49:46 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char_width_handler(t_properties *flag, int printed)
{
	int	i;

	i = 0;
	while (i < (flag->width - printed) && ++i)
	{
		if (flag->place_zero)
			ft_put_char('0');
		else if (flag->place_space)
			ft_put_char(' ');
	}
	return (i);
}

int	ft_char_handler(t_properties *flag, va_list ptr)
{
	int	printed;

	printed = 0;
	if (flag->type == 's')
		printed = ft_str_print(va_arg(ptr, char *), flag);
	else if (flag->type == 'c')
	{
		if (!flag->l_aligned && flag->width != -1)
			printed += ft_char_width_handler(flag, 1);
		printed += ft_put_char(va_arg(ptr, int));
		if (flag->l_aligned && flag->width != -1)
			printed += ft_print_l_aligned(flag, printed);
	}
	return (printed);
}

int	ft_none_handler(t_properties *flag)
{
	int	printed;

	printed = 0;
	if (!flag->l_aligned && flag->width != -1)
		printed += ft_char_width_handler(flag, 1);
	printed += ft_put_char((int)flag->type);
	if (flag->l_aligned && flag->width != -1)
		printed += ft_print_l_aligned(flag, printed);
	return (printed);
}

int	ft_str_print(char *a, t_properties *flag)
{
	int	i;
	int	printed;

	printed = ft_strlen(a);
	if (flag->preci != -1 && flag->preci < printed)
		printed = flag->preci;
	if (flag->preci == -1)
		flag->preci = ft_strlen(a);
	if (flag->l_aligned != 1 && flag->width != -1)
		printed += ft_char_width_handler(flag, printed);
	if (!a)
		ft_put_null(flag);
	else
	{
		i = -1;
		while (a[++i] && i < flag->preci)
			ft_put_char(a[i]);
	}
	if (flag->l_aligned && flag->width != -1)
		printed += ft_print_l_aligned(flag, printed);
	return (printed);
}
