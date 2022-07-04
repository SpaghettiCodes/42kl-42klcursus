/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:11:54 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/04 12:11:55 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*)){
	t_list	*current;
	t_list	*temp;

	if (*lst && del) {
		current = *lst;
		while (current) {
			temp = current->next;
			ft_lstdelone(current, del);
			current = temp;
		}
		free(temp);
		*lst = 0;
	}
}
