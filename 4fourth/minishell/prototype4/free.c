#include "minishell.h"

void	delete_token_node(t_token **current)
{
	if ((*current)->string)
		free ((*current)->string);
	free ((*current));
	(*current) = NULL;
}

// why does this exists..?
// void	delete_specific_token(t_token **main, int index)
// {
// 	t_token	*prev;
// 	t_token *temp;
// 	t_token	*cur;

// 	prev = NULL;
// 	cur = (*main);
// 	while (index)
// 	{
// 		prev = cur;
// 		cur = cur->next;
// 		--index;
// 	}
// 	temp = cur->next;
// 	delete_token_node(&cur);
// 	if (prev)
// 		prev->next = temp;
// 	else
// 		(*main) = temp;
// }

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

void	delete_var_node(t_val *node)
{
	if (node->alloced)
		free(node->theline);
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

void	free_darray(char **stuff)
{
	size_t	i;

	i = 0;
	// debug
	// printf("Freeing double arrays\n");
	while ( stuff[i] )
	{
		// debug
		// printf("freeing %ld = %s\n", i, stuff[i]);
		free(stuff[i]);
		++i;
	}
	free(stuff);
}

void	free_cmd(t_cmd **cmd)
{
	t_cmd	*temp;
	t_cmd	*cur;

	cur = (*cmd);
	while (cur)
	{
		temp = cur->next;
		if ( cur->final_cmd_line );
			free_darray( cur->final_cmd_line );
		free(cur);
		cur = temp;
	}
	*cmd = NULL;
}

void	free_cmd_info(t_cmd_info *info)
{
	if (info->cmd)
		free_cmd(&info->cmd);
}