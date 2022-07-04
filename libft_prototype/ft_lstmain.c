#include "ft_lstnew.c"
#include "ft_lstadd_front.c"
#include "ft_lstsize.c"
#include "ft_lstadd_back.c"
#include "ft_lstclear.c"
#include "ft_lstiter.c"
#include "ft_lstmap.c"
#include "libft.h"
#include <stdio.h>

void del(void *thing) {
	return ;
}

void* times2(void *thing){
	char *a;
	a = (char *) thing;
	*a = *a + 20;
	return ((void *) a);
}

void add(void *thing){
	char *a;

	a = (char *) thing;
	*a -= 32;
}

int main(){
	// test ft_lstnew
	printf("Testing lstnew\n\n");
	char a = 'a', b = 'b';
	char *content = &a, *content2 = &b;
	t_list **test, *test2;
	test = (t_list **) malloc (sizeof(t_list *));
	*test = ft_lstnew(content);
	printf("New node: %c\n", *((char *) (*test)->content));

	//test ft_lstadd_front
	printf("\nTesting lstadd_front\n\n");
	test2 = ft_lstnew(content2);
	printf("To add in front: %c\n", *((char *) test2->content));
	ft_lstadd_front(test, test2);
	int i = 1;
	for (t_list *current = *test; current; current = current->next, i++)
		printf("Node %d: %c\n",i,  *((char *) current->content));

	// test ft_lstsize
	printf("\nTesting ft_lstsize\n\n");
	printf("Number of Nodes = %d\n", ft_lstsize(*test));

	// test ft_lstadd_back
	printf("\nTesting lstadd_back\n\n");
	char c = 'c';
	char *content3 = &c;
	t_list *test3 = ft_lstnew(content3);
	printf("To add at the back: %c\n", *((char *) test3->content));
	ft_lstadd_back(test, test3);
	i = 1;
	for (t_list *current = *test; current; current = current->next, i++)
		printf("Node %d: %c\n",i,  *((char *) current->content));

	// test ft_lstiter
	printf("\nTesting ft_lstiter\n\n");
	printf("Before\n");
	i = 1;
	for (t_list *current = *test; current; current = current->next, i++)
		printf("Node %d: %c (%d)\n",i,  *((char *) current->content), *((char *) current->content));
	ft_lstiter(*test, add);
	printf("Capitalizing...\n");
	i = 1;
	for (t_list *current = *test; current; current = current->next, i++)
		printf("Node %d: %c (%d)\n",i,  *((char *) current->content), *((char *) current->content));

	// test ft_lstmap
	printf("\nTesting lstmap\n\n");
	t_list *test5 = NULL;
	test5 = ft_lstmap(*test, times2, del);
	i = 1;
	printf("Test list has:\n");
	for (t_list *current = *test; current; current = current->next, i++)
		printf("Node %d: (%d)\n",i,  *((char *) current->content), *((char *) current->content));
	printf("Test5 list has:\n");
	i = 1;
	if (!test5){
		printf("nothing, it has nothing\n");
	} else {
	for (t_list *current = test5; current; current = current->next, i++)
		printf("Node %d: (%d)\n",i,  *((char *) current->content), *((char *) current->content));
	}

	// test ft_lstclear + ft_lstdelone
	printf("\nTesting lstclear and lstdelone\n\n");
	ft_lstclear(test, del);
	if (!(*test))
		printf("Mem cleared\n");

}
