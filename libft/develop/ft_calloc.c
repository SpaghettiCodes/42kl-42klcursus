/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:11:00 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/06 14:58:52 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*result;

	if (nitems > SIZE_MAX / size)
        return (NULL);
	result = malloc (nitems * size);
	if (!result)
		return (0);
	ft_bzero(result, (nitems * size));
	return (result);
}
