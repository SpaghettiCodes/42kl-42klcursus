#include "push_swap.h"

int	count_instruct(t_instructions *instruct)
{
	t_instructions *current; 
	int	counter;

	counter = 0;
	current = instruct;
	while (current && current->move)
	{
		++counter;
		current = current->next;
	}
	return (counter);
}

void	del_all(t_instructions **instructions)
{
	t_instructions	*tmp;

	while (instructions && *instructions)
	{
		tmp = (*instructions)->next;
		if ((*instructions)->move)
			free((*instructions)->move);
		free(*instructions);
		*instructions = tmp;
	}
}

t_instructions *init_instruction()
{
	t_instructions *instruction;
	instruction = malloc (sizeof(t_instructions));
	instruction->move = NULL;
	instruction->next = NULL;
	return (instruction);
}

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

void	init_stacks(t_pushswap *stack)
{
	if (stack->stack_a)
		free(stack->stack_a);
	if (stack->instructions)
		del_all(&stack->instructions);
	stack->instructions = init_instruction();
	stack->stack_a = int_dup(stack->un_sorted, stack->total_size);
	stack->a_size = stack->total_size;
	if (stack->stack_b)
		free(stack->stack_b);
	stack->stack_b = malloc (sizeof(int) * stack->total_size);
	stack->b_size = 0;
}