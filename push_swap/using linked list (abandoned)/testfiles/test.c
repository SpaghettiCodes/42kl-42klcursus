#include "pushswap.h"
#include <stdio.h>

// t_stack	*initialize(char *nbr, t_stack *head)
// {
// 	t_stack *stack;

// 	stack = (t_stack *) malloc (sizeof(t_stack));
// 	stack->num = ft_atoi(nbr, head);
// 	stack->next = NULL;
// 	return (stack);
// }

// t_stack	*makestack(int ac, char **av)
// {
// 	int	i;
// 	t_stack *stack;
// 	t_stack *current;

// 	stack = initialize(av[1], stack);
// 	current = stack;
// 	i = 1;
// 	while (++i < (ac - 1))
// 	{
// 		current->next = initialize(av[i], stack);
// 		current = current->next;
// 	}
// 	current->next = initialize(av[i], stack);
// 	return (stack);
// }

void	printstack(t_stack *stack)
{
	t_stack *current;

	for (current = stack; current; current = current->next)
		printf("%d ", current->num);
	printf("\n");
	return ;
}

int main()
{
	t_stack *list;
	t_stack *list2;
	list2 = (t_stack *) malloc (sizeof(t_stack));
	list2 = NULL;
	int ac = 8;
	char *av[] = {
		"epic",
		"1",
		"2",
		"3",
		"5",
		"10",
		"69",
		"12"
	};
	list = makestack(ac, av);
	printf("Before\n");
	printstack(list);

	swap(&list);

	printf("swap a\n");
	printstack(list);

	shift_right(&list);

	printf("reverse rotate\n");
	printstack(list);

	shift_left(&list);
	shift_left(&list);

	printf("rotate\n");
	printstack(list);

	push(&list, &list2);
	push(&list, &list2);

	printf("push\n");
	printstack(list);
	printstack(list2);

	push(&list2, &list);

	printf("push other way\n");
	printstack(list);
	printstack(list2);
}
