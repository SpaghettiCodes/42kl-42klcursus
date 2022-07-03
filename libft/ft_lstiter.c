#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *)){
	t_list	*current;

	if (lst && f){
		current = lst;
		while (current){
			f(current->content);
			current = current->next;
		}
	}
}
