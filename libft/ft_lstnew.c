/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:12:03 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/04 12:12:04 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content){
	t_list	*list;

	if (!(list = (t_list *) malloc (sizeof(list))))
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
