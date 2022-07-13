// #include <stdio.h>
// # include <stdlib.h>
// # include <fcntl.h>
// # include <unistd.h>

// typedef struct List{
// 	int fd;
// 	int	readuntil;
// 	char *contents;
// 	struct List* next;
// } fd_list;

// void	fd_search_and_destroy(int fd, fd_list **list)
// {
// 	fd_list	*current;
// 	fd_list	*prev;
// 	fd_list	*temp;

// 	current = *list;
// 	prev = NULL;
// 	while (current)
// 	{
// 		if (current->fd == fd)
// 			break ;
// 		prev = current;
// 		current = current->next;
// 	}
//     if (!current)
//         return ;
// 	temp = current->next;
// 	if (current->contents)
// 		free(current->contents);
// 	free(current);
// 	current = temp;
// 	if (prev)
// 		prev->next = current;
//     else
//         *list = current;
// }

// fd_list *fd_initialize(int fd)
// {
// 	fd_list	*list;

// 	list = (fd_list *) malloc (sizeof(fd_list));

// 	list->fd = fd;
// 	list->next = NULL;
// 	list->contents = NULL;
// 	list->readuntil = 0;
// 	return (list);
// }

// fd_list	*fd_search_and_add(int fd, fd_list *list)
// {
// 	fd_list	*current;

// 	current = list;
// 	while (1)
// 	{
// 		if (current->fd == fd)
// 			return (current);
// 		if (!current->next)
// 			break ;
// 		current = current->next;
// 	}
// 	current->next = fd_initialize(fd);
// 	return (current->next);
// }

// int main()
// {
//     fd_list *list;
//     list = fd_initialize(1);
//     for (int i = 1; i < 9; i++)
//         fd_search_and_add(i, list);
//     printf("Before: ");
//     for (fd_list *current = list; current; current = current->next)
//         printf("%d ", current->fd);
//     printf("\nAfter: ");
//     fd_search_and_destroy(1, &list);
//     for (fd_list *current = list; current; current = current->next)
//         printf("%d ", current->fd);
//     printf("\nAfter: ");
//     fd_search_and_destroy(3, &list);
//     for (fd_list *current = list; current; current = current->next)
//         printf("%d ", current->fd);
//     printf("\nAfter: ");
//     fd_search_and_destroy(8, &list);
//     for (fd_list *current = list; current; current = current->next)
//         printf("%d ", current->fd);
//     printf("\nAfter: ");
//     fd_search_and_destroy(18, &list);
//     for (fd_list *current = list; current; current = current->next)
//         printf("%d ", current->fd);
// }