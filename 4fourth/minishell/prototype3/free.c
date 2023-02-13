#include "minishell.h"

void	delete_token_node(t_token **current)
{
	if ((*current)->string)
		free ((*current)->string);
	free ((*current));
	(*current) = NULL;
}

void	delete_specific_token(t_token **main, int index)
{
	t_token	*prev;
	t_token *temp;
	t_token	*cur;

	prev = NULL;
	cur = (*main);
	while (index)
	{
		prev = cur;
		cur = cur->next;
		--index;
	}
	temp = cur->next;
	delete_token_node(&cur);
	if (prev)
		prev->next = temp;
	else
		(*main) = temp;
}

void	remove_all_token(t_token **stuff)
{
	t_token	*temp;
	t_token *current;

	current = (*stuff);
	while (current)
	{
		temp = current->next;
		delete_token_node(&current);
		current = temp;
	}
	(*stuff) = NULL;
}

void	free_darray(char ***paths)
{
	size_t	i;

	i = 0;
	while ((*paths)[i])
	{
		free((*paths)[i]);
		++i;
	}
	free((*paths));
	*paths = NULL;
}

void	delete_var_node(t_val *node)
{
	if (node->keyword)
		free(node->keyword);
	if (node->define)
		free(node->define);
}

void	delete_all_var(t_val **var)
{
	t_val *temp;

	temp = NULL;
	while ((*var))
	{
		temp = (*var)->next;
		delete_var_node(*var);
		free(*var);
		*var = temp;
	}
}
