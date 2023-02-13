#include "minishell.h"

// variable use is put on hold because what the fuck? am i doing

t_token	*new_assignvar_node(char *cmd, int start, int end, t_token *current)
{
	current->string = ft_substr2(cmd, start, end);

	if (current->string[0] == '$')
		current->type = 1;
	else
		current->type = 0;

	current->next = init_token(current->token_no + 1);
	return (current->next);
}

void	delete_token_node(t_token **current)
{
	free ((*current)->string);
	free ((*current));
	(*current) = NULL;
}

void	delete_tokens(t_token **stuff)
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

void	replace_variable(char *cmd, t_val *global_var, t_val *private_val)
{
	t_token	*funny;
	t_token *current;
	int	start;
	int	i;
	int	total_length;

	funny = init_token(0);
	current = funny;
	i = 0;
	start = 0;
	total_length = ft_strlen(cmd);
	while (i <= total_length)
	{
		if (cmd[i] == '$')
		{
			if (start - i)
				current = new_assignvar_node(cmd, start, (i - 1), current);
			current = new_assignvar_node("$", 0, 1, current);
			start = (i + 1);
		}
		else if (cmd[i] == '\0' || cmd[i] == SPACE_sym)
		{
			if (start - i)
				current = new_assignvar_node(cmd, start, (i - 1), current);
			break ;
		}
		++i;
	}
	printf("replace_variable tokens = \n");
	for (current = funny; current; current = current->next)
	{
		if (!current->string)
			printf("(null)\n");
		else
			printf("%s\n", current->string);
	}
	delete_tokens(&funny);
	printf("replace_var tokens deleted\n");
}