/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:06:01 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/18 13:17:45 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	eprint(char *element, char *msg)
{
	write(2, "pipex: ", 7);
	if (element)
		write(2, element, ft_strlen(element));
	write(2, ": ", 2);
	if (msg)
		write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return (11 + ft_strlen(element) + ft_strlen(msg));
}
