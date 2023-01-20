/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:06:01 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/21 00:25:48 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	eprint(char *element, char *msg)
{
	int		ret_val;
	char	*error_msg;

	error_msg = n_append("pipex : ", element);
	error_msg = append(error_msg, " : ");
	error_msg = append(error_msg, msg);
	error_msg = append(error_msg, "\n");
	ret_val = ft_strlen(error_msg);
	write (2, error_msg, ret_val);
	free(error_msg);
	return (ret_val);
}
