#include "push_swap.h"

int	init_chunk(t_pushswap *stack)
{
	if (stack->stack_b[0] < stack->stack_b[1])
		sb(stack);
	pa(stack);
	pa(stack);
	ra(stack);
	return (0);
}

t_instructions	*init_instruct_node()
{
	t_instructions *instruction;
	instruction = malloc (sizeof(t_instructions));
	instruction->move = NULL;
	instruction->next = NULL;
	return (instruction);
}


void	init_stacks(t_pushswap *stack)
{
	if (stack->stack_a)
		free(stack->stack_a);
	if (stack->instructions)
		del_all(&stack->instructions);
	if (stack->stack_b)
		free(stack->stack_b);
	stack->instructions = init_instruct_node();
	stack->stack_a = int_dup(stack->un_sorted, stack->total_size);
	stack->a_size = stack->total_size;
	stack->stack_b = malloc (sizeof(int) * stack->total_size);
	stack->b_size = 0;
}