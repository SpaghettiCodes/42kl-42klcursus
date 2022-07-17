#include "pushswap.h"

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

void	shift_right(t_stack **dest)
{
	t_stack *last;
	t_stack *before_last;
	t_stack *head;

	last = (*dest);
	head = (*dest);
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = head;
	*dest = last;
}

void	shift_left (t_stack **dest)
{
	t_stack *last;
	t_stack *before_last;
	t_stack *head;

	last = (*dest);
	head = (*dest);
	while (last->next)
		last = last->next;

	last->next = head;
	*dest = head->next;
	head->next = NULL;
}

void	reverserotate(t_stack *tab)
{
	shift_right(&tab);
}

void	rotate(t_stack *tab)
{
	shift_left(&tab);
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack *current_src;
	t_stack *current_dest;
	t_stack *temp;

	current_src = (*src);
	current_dest = (*dest);

	(*src) = current_src->next;
	current_src->next = current_dest;
	(*dest) = current_src;
}
