/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:12:07 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/04 12:41:24 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstdupfunc(t_list *src, void *(*f)(void *))
{
	t_list	*dest;
	t_list	*curt_dest;
	t_list	*curt_src;

	if (src)
	{
		dest = (t_list *) malloc (sizeof(t_list));
		curt_dest = dest;
		curt_src = src;
		while (curt_src)
		{
			curt_dest->content = f(curt_src->content);
			if (curt_src->next)
				curt_dest->next = (t_list *) malloc (sizeof(t_list));
			else
				curt_dest->next = NULL;
			curt_dest = curt_dest->next;
			curt_src = curt_src->next;
		}
		return (dest);
	}
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	(void)(del);
	return (ft_lstdupfunc(lst, f));
}
