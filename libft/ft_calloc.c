/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:11:00 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/04 12:11:01 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size){
	void	*result;

	if (!nitems || !size)
		return 0;
	result = malloc (nitems * size);
	if (!result)
		return 0;
	ft_bzero(result, (nitems * size));
	return (result);
}
