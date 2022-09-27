#include "pushswap.h"

int	countelem(t_stack **stacka)
{
	int i;
	t_stack	*current;

	i = 0;
	current = (*stacka);
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

// this is garbage and will probably not work
int	solve_four_and_five(t_stack **stacka, t_stack **stackb)
{
	while(countelem(stacka) >= 2)
	{
		push(stacka, stackb);
	}
	solve_two(stacka);
	if (countelem(stackb) == 3)
	{
		solve_three(stackb);
	}
	else
	{
		solve_two(stackb);
	}

}

int	solve_two(t_stack **stacka)
{
	int a;
	int b;

	a = (*stacka)->num;
	b = (*stacka)->next->num;
	if (a > b)
		sa(stacka);
	return (2);
}

int	solve_three(t_stack **stacka)
{
	int a;
	int b;
	int c;

	a = (*stacka)->num;
	b = (*stacka)->next->num;
	c = (*stacka)->next->next->num;
	if (b < c && c < a)
		ra(stacka);
	else if ((c < b && b < a))
	{
		sa(stacka);
		rra(stacka);
	}
	else if (c < a && a < b)
		rra(stacka);
	else if (b < a && a < c)
		sa(stacka);
	else if (a < c && c < b)
	{
		rra(stacka);
		sa(stacka);
	}
	return (3);
}
