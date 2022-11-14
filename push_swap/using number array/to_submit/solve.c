#include "push_swap.h"

void	print_instruction(t_instructions *instruction)
{
	t_instructions *current;

	current = instruction;
	while (current && current->move)
	{
		write(1, current->move, str_len(current->move));
		current = current->next;
	}
}

void solve(t_pushswap *stack)
{
	init_stacks(stack);
	if (stack->total_size == 2)
		solve_two(stack);
	else if (stack->total_size == 3)
		solve_three(stack);
	else if (stack->total_size < 100)
		solve_small_big(stack);
	else 
		solve_very_big(stack);
	print_instruction(stack->instructions);
}
