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
