#include "libft.h"
#include "ft_lstlast.c"

void	ft_lstadd_back(t_list **lst, t_list *new){
	t_list	*current;

	if (!new)
		return ;
	if (*lst) {
		current = ft_lstlast(*lst);
		current->next = new;
	} else
		*lst = new;
}
