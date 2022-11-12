/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:28:54 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/17 18:49:46 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	met_percent(const char *str, va_list ptr, int *printed)
{
	t_properties	*flag;
	int				i;

	flag = ft_initialize_flag();
	i = format_handler(flag, (char *)str, ptr, printed);
	free(flag);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		check;
	int		printed;
	va_list	ptr;

	i = -1;
	printed = 0;
	va_start(ptr, str);
	while (str[++i])
	{
		if (str[i] != '%')
			printed += ft_put_char(str[i]);
		else
		{
			check = met_percent(&str[i], ptr, &printed);
			if (check == -1)
			{
				printed += ft_put_char(str[i]);
				continue ;
			}
			i += check;
		}
	}
	va_end(ptr);
	return (printed);
}
