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

t_instructions *last_node(t_instructions *instruction)
{
	t_instructions	*current;
	
	current = instruction;
	while (current->move)
		current = current->next;
	return (current);
}

void	add_node(t_instructions *instruction, char *move)
{
	t_instructions *current;
	
	current = last_node(instruction);
	current->move = str_dup(move);
	current->next = init_instruct_node();
}