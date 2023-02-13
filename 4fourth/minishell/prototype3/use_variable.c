#include "minishell.h"

// variable use is put on hold because what the fuck? am i doing

t_token	*new_assignvar_node(char *cmd, int start, int end, t_token *current)
{
	current->string = ft_substr2(cmd, start, end);
	current->type = (current->string[0] == '$');
	// if (current->string[0] == '$')
	// 	current->type = 1;
	// else
	// 	current->type = 0;
	current->next = init_token(current->token_no + 1);
	return (current->next);
}

void	replace_token_var(t_token **tokens, t_val *global_var, t_val *private_val)
{
	int	index;
	t_token *cur;
	t_token	*temp;
	t_val	*search;

	cur = (*tokens);
	index = 0;
	printf("Replacing..\n");
	while (cur && cur->string)
	{
		printf("Doing..\n");
		if (cur->type)
		{
			temp = cur->next;
			printf("Deleting & node\n");
			delete_specific_token(tokens, index);
			printf("Deleted\n");
			cur = temp;
			search = search_variable(cur->string, global_var);
			if (!search)
				search = search_variable(cur->string, private_val);
			if (cur->string)
				free(cur->string);
			if (!search)
				cur->string = ft_strdup("");
			else
				cur->string = ft_strdup(search->define);
		}
		printf("Done one\n");
		++index;
		cur = cur->next;
	}
}

void	replace_variable(char **cmd, t_val *global_var, t_val *private_val)
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
			if ((*cmd)[i] == SPACE_sym)
				current = new_assignvar_node("_", 0, 1, current);
			break ;
		}
		++i;
	}

	// debug
	printf("replace_variable tokens = \n");
	for (current = sub_token; current; current = current->next)
	{
		if (!current->string)
			printf("(null)\n");
		else
			printf("%s\n", current->string);
	}

	replace_token_var(&sub_token, global_var, private_val);
	printf("Done all\n");

	printf("Replaced: \n");
	for (current = sub_token; current; current = current->next)
	{
		if (!current->string)
			printf("(null)\n");
		else
			printf("%s\n", current->string);
	}

	free((*cmd));
	(*cmd) = token_to_string(sub_token);

	remove_all_token(&sub_token);
	printf("replace_var tokens deleted\n");
}