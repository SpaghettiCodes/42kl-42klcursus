#include "minishell.h"

// variable use is put on hold because what the fuck? am i doing

void	free_val_content(t_val *current)
{
	if (current->alloced)
		free(current->theline);
}

t_val	*init_val()
{
	t_val *new;

	new = malloc (sizeof(t_val));
	new->theline = NULL;
	new->alloced = 0;
	new->type = SELF;
	new->next = NULL;
	return (new);
}

// replaces current node string with new string, STRING IS EXPECTED TO BE ALLOCED, WILL ALWAYS TURN NOT ALLOCED TO ALLOCED
void	replace_val(t_val *current, char *string, int equalloc)
{
	if (current->alloced && current->theline)
		free(current->theline);
	current->theline = string;
	current->equalloc = equalloc;
	current->alloced = 1;
}

// fills up value with given parameters, WILL ALWAYS ASSUME TYPE IS SELF DEF
void	fill_val(t_val *current, bool is_alloc, char *string, int equalloc)
{
	current->alloced = is_alloc;
	current->equalloc = equalloc;
	current->theline = string;
	current->type = SELF;
}

t_val	*add_back_variable(t_val **variables)
{
	t_val *current;

	if (!(*variables))
	{
		(*variables) = init_val();
		return ((*variables));
	}
	current = *variables;
	while (current->next)
		current = current->next;
	current->next = init_val();
	return (current->next);
}

t_val	*search_variable(char *keyword, t_val *var)
{
	t_val	*current;

	if (!var)
		return (NULL);
	current = var;
	if (current->theline)
	{
		while (current)
		{
			if (!ft_strncmp(current->theline, keyword, current->equalloc))
				break;
			current = current->next;
		}
		return (current);
	}
	return (NULL);
}

bool	new_variable(char *input, t_val **global_var, bool alloc)
{
	int		equal_loc;
	int		length;
	char	*keyword;
	t_val	*current;

	equal_loc = search_character(input, '=', 0, MAX_SIZE);
	// keyword cant have /
	if (equal_loc == 0 || search_character(input, '/', 0, equal_loc) != -1)
		return FALSE;
	length = ft_strlen(input);
	length = length - (input[length - 1] == SPACE_sym);

	keyword = ft_substr2(input, 0, (equal_loc - 1));
	current = search_variable(keyword, (*global_var));
	free(keyword);
	if (!current)
	{
		// debug
		printf("nope not found\n");
		current = add_back_variable(global_var);
		current->type = SELF;
	}
	replace_val(current, ft_strdup(input), equal_loc);
	// debug
	printf("is this garbage working [the line {%s}, after equal location {%s}]\n", current->theline, &current->theline[current->equalloc + 1]);
	return (TRUE);
}

t_val	*get_envval(char **envp)
{
	t_val *ret;
	t_val *current;
	int	i;
	int	equal_loc;

	i = 0;
	ret = init_val();
	current = ret;
	while (envp[i])
	{
		equal_loc = search_character(envp[i], '=', 0, MAX_SIZE);
		fill_val(current, 0, envp[i], equal_loc);
		current->type = ENV;
		if (envp[i + 1])
		{
			current->next = init_val();
			current = current->next;
		}
		i++;
	}
	return (ret);
}
