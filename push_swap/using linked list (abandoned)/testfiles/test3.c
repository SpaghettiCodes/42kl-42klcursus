#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int				num;
	struct s_stack *next;
}	t_stack;

static int	ft_isspace(char c)
{
	return ((c == 32) || (c >= 9 && c <= 13));
}

static int	overflow(int result, int neg, char nextnum)
{
	if (result <= 214748364)
	{
		if (result == 214748364)
		{
			if ((nextnum <= '7' && neg == 1) || (nextnum <= '8' && neg == -1))
				return (1);
		}
		else
			return (1);
	}
	return (0);
}

int	ft_atoi(const char *str, t_stack *stack)
{
	int	result;
	int	negative;
	int	i;

	i = 0;
	result = 0;
	negative = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' && ++i)
		negative = -1;
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * negative);
}

t_stack	*initialize(char *nbr, t_stack *head)
{
	t_stack *stack;

	stack = (t_stack *) malloc (sizeof(t_stack));
	stack->num = ft_atoi(nbr, head);
	stack->next = NULL;
	return (stack);
}

t_stack	*makestack(int ac, char **av)
{
	int	i;
	t_stack *stack;
	t_stack *current;

	stack = initialize(av[1], stack);
	current = stack;
	i = 1;
	while (++i < (ac - 1))
	{
		current->next = initialize(av[i], stack);
		current = current->next;
	}
	current->next = initialize(av[i], stack);
	return (stack);
}

void	swap(t_stack **stack)
{
	t_stack *current;
	t_stack *after_current;

	if (!(*stack) || !((*stack)->next))
		return ;

	current = *stack;
	after_current = current->next;

	current->next = after_current->next;
	after_current->next = current;
	*stack = after_current;
}

int sa(t_stack **stack)
{
	swap(stack);
}

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
		"6",
		"7",
		"8"
	};
	list = makestack(ac, av);
	printf("Before\n");
	printstack(list);

	sa(&list);

	printf("swap a\n");
	printstack(list);
}
