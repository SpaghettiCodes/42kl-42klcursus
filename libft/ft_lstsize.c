/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:12:09 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/04 12:12:10 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst){
	int		i;
	t_list	*current;

	if (!lst)
		return 0;
	i = 0;
	current = lst;
	while (current){
		i++;
		current = current->next;
	}
	return (i);
}
