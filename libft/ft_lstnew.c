#include "libft.h"

t_list *ft_lstnew(void *content){
	t_list *list;

	if (!(list = (t_list *) malloc (sizeof(list))))
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
