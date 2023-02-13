#include "minishell.h"

// variable use is put on hold because what the fuck? am i doing

void	free_internal_val(t_val *current)
{
	if (current->keyword)
		free(current->keyword);
	if (current->define)
		free(current->define);
}

t_val	*init_val()
{
	t_val *new;

	new = malloc (sizeof(t_val));
	new->keyword = NULL;
	new->define = NULL;
	new->next = NULL;
	return (new);
}

void	fill_val(t_val *current, char *keyword, char *define)
{
	current->keyword = keyword;
	current->define = define;
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (-1);
	while (str1[i] == str2[i])
	{
		if (str1[i] == '\0' && str2[i] == '\0')
			return 0;
		++i;
	}
	return (str1[i] - str2[i]);
}

t_val	*add_back_local(t_val *local_var)
{
	t_val *current;

	current = local_var;
	while (current->define && current->next)
		current = current->next;
	current->next = init_val();
	return (current);
}

t_val	*search_variable(char *keyword, t_val *var)
{
	t_val	*current;

	current = var;
	if (current->keyword)
	{
		while (current)
		{
			if (!ft_strcmp(current->keyword, keyword))
				break;
			current = current->next;
		}
		return (current);
	}
	return (NULL);
}

bool	new_variable(char *input, t_val *local_var)
{
	int		equal_loc;
	int		length;
	char	*keyword;
	t_val	*current;

	equal_loc = search_element(input, '=', 0, MAX_SIZE);
	// keyword cant have /
	if (equal_loc == 0 && search_element(input, '/', 0, equal_loc))
		return FALSE;
	length = ft_strlen(input);
	length = length - (input[length - 1] == SPACE_sym);
	keyword = ft_substr2(input, 0, (equal_loc - 1));
	current = search_variable(keyword, local_var);
	if (!current)
	{
		printf("nope not found\n");
		current = add_back_local(local_var);
	}

	free_internal_val(current);
	fill_val(current, keyword, ft_substr2(input, equal_loc + 1, (length - 1)));
	printf("is this garbage working %s = %s\n", current->keyword, current->define);
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
		equal_loc = search_element(envp[i], '=', 0, MAX_SIZE);
		fill_val(current, ft_substr2(envp[i], 0, equal_loc - 1), ft_substr2(envp[i], equal_loc + 1, -1));
		if (envp[i + 1])
		{
			current->next = init_val();
			current = current->next;
		}
		i++;
	}
	return (ret);
}
