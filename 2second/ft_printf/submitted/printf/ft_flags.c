/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:28:31 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/17 18:49:46 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_flag(t_properties *flag)
{
	flag->type = '\0';
	flag->prefix = 0;
	flag->l_aligned = 0;
	flag->sign = 0;
	flag->place_space_front = 0;
	flag->width = -1;
	flag->place_space = 0;
	flag->place_zero = 0;
	flag->preci = -1;
}

t_properties	*ft_initialize_flag(void)
{
	t_properties	*flag;

	flag = (t_properties *) malloc (sizeof(t_properties));
	ft_reset_flag(flag);
	return (flag);
}

int	print_flag(t_properties *flag, va_list ptr, int *printed)
{
	*printed = *printed + ft_convertion(flag, ptr);
	return (1);
}

int	format_handler(t_properties *flag, char *c, va_list ptr, int *printed)
{
	int	i;

	i = 1;
	while (check_flag(flag, c[i]))
		i++;
	if (check_width(flag, c[i]) != 0)
	{
		if (flag->width == -2)
			i++;
		else
		{
			flag->width = ft_atoi(&c[i]);
			while ((c[i] >= '0' && c[i] <= '9'))
				i++;
		}
	}
	if (c[i] == '.' && ++i)
		i += check_preci(flag, &c[i]);
	flag->type = c[i];
	if (flag->type == '\0')
		return (-1);
	print_flag(flag, ptr, printed);
	return (i);
}
