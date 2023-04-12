#include "minishell.h"

// variable use is put on hold because what the fuck? am i doing

t_token	*new_assignvar_node(char *cmd, int start, int end, t_token *current)
{
	current->string = ft_substr2(cmd, start, end);
	current->type = (current->string[0] == '$');
	current->next = init_token(current->token_no + 1);
	return (current->next);
}

void	replace_token_var(t_token **tokens, t_cmd_info *minishell)
{
	int	index;
	t_token *cur;
	t_token *prev;
	t_token	*temp;
	t_val	*search;

	cur = (*tokens);
	prev = NULL;
	index = 0;
	printf("Replacing..\n");
	while (cur && cur->string)
	{
		if (cur->type)
		{
			printf("Deleting & node\n");
			temp = cur->next;
			delete_token_node(&cur);
			(prev) ? (prev->next = temp) : ((*tokens) = temp);
			cur = temp;
			printf("Deleted\n");

			if (!ft_strcmp("?", cur->string))
				cur->string = ft_itoa(minishell->last_exit);
			else
			{			
				search = search_variable(cur->string, minishell->global_var);
				if (cur->string)
					free(cur->string);
				if (!search)
					cur->string = ft_strdup("");
				else
					cur->string = ft_strdup(&search->theline[search->equalloc + 1]);
			}
		}
		printf("Done one\n");
		++index;
		prev = cur;
		cur = cur->next;
	}
}

// debug
void	printtoken(t_token *stuff)
{
	t_token *current;

	printf("replace_variable tokens = \n");
	for (current = stuff; current; current = current->next)
	{
		if (!current->string)
			printf("(null)\n");
		else
			printf("%s\n", current->string);
	}
}

void	replace_variable(char **cmd, t_cmd_info *minishell)
{
	t_token	*sub_token;
	t_token *current;
	int	start;
	int	i;
	int	total_length;

	sub_token = init_token(0);
	current = sub_token;
	i = 0;
	start = 0;
	total_length = ft_strlen((*cmd));
	printf("Seperating variables\n");
	while (i <= total_length)
	{
		if ((*cmd)[i] == '$' || (*cmd)[i] == '=' || (*cmd)[i] == '\"' || 
				(*cmd)[i] == SPACE_sym || (*cmd)[i] == '\'')
		{
			if (start - i)
				current = new_assignvar_node(*cmd, start, (i - 1), current);
			current = new_assignvar_node(((*cmd) + i), 0, 0, current);
			start = (i + 1);
		}
		else if ((*cmd)[i] == '\0')
		{
			if (start - i)
				current = new_assignvar_node(*cmd, start, (i - 1), current);
			break ;
		}
		++i;
	}

	// debug
	printtoken(sub_token);

	replace_token_var(&sub_token, minishell);

	// debug
	printf("Done all\n");
	printf("Replaced: \n");
	printtoken(sub_token);

	free((*cmd));
	(*cmd) = token_to_string(sub_token);

	remove_all_token(&sub_token);

	// debug
	printf("replace_var tokens deleted\n");
	printf("new cmd = %s\n", (*cmd));
}