#include "minishell.h"

bool	is_alpha(char check)
{
	return ((check >= 'A' && check <= 'Z' || check >= 'a' && check <= 'z'));
}

int	export_error(char *aspect)
{
	char *msg;

	msg = n_append("\'", aspect);
	msg = append(msg, "\' not a valid i	dentifier");
	eprint("export", msg);
	free(msg);
	return (1);
}

int	add_var(char **arg, t_val *global_variable)
{
	char	*keyword;
	int		i;
	int		equal_loc;
	int		there_was_error;
	t_val	*searcher;

	i = 1;
	there_was_error = 0;
	while (arg[i])
	{
		if (!is_alpha(arg[i][0]))
			there_was_error = export_error(arg[i]);
		else
		{
			equal_loc = search_character(arg[i], '=', 0, MAX_SIZE);
			if (equal_loc == -1)
				equal_loc = ft_strlen(arg[i]);
			keyword = ft_substr2(arg[i], 0, equal_loc - 1);
			searcher = search_variable(keyword, global_variable);
			free(keyword);
			if (!searcher)
			{
				searcher = add_back_variable(&global_variable);
				fill_val(searcher, 1, ft_strdup(arg[i]), equal_loc);
			}
			else
			{
				if (equal_loc != ft_strlen(arg[i]))
					replace_val(searcher, ft_strdup(arg[i]), equal_loc);
			}
		}
		++i;
	}
	return (there_was_error);
}

// a really simple sort algo, will fix eventually
void	sort_variables(char **variables)
{
	char	*temp;
	int	i;
	int	j;

	i = count_arg(variables);
	j = 0;
	while (j < i)
	{
		if (variables[j + 1])
		{
			if (ft_strcmp(variables[j], variables[j + 1]) > 0)
			{
				temp = variables[j];
				variables[j] = variables[j + 1];
				variables[j + 1] = temp;
				j = 0;
			}
		}
		++j;
	}
	return ;
}

// whoops
// write(1, temp[i], equal_loc);
// write(1, " ", 1);
// write(1, &temp[i][equal_loc + 1], ft_strlen(temp[i]) - equal_loc);
int	export_print(t_val *global_variable)
{
	int		i;
	int		equal_loc;
	char	**temp;

	i = 0;
	temp = variable_to_darray(global_variable);
	sort_variables(temp);
	while (temp[i])
	{
		equal_loc = search_character(temp[i], '=', 0, -1);
		if (equal_loc == -1)
			equal_loc = ft_strlen(temp[i]);
		write(1, "declare -x ", 11);
		write(1, temp[i], equal_loc);
		write(1, "=\"", 2);
		write(1, &temp[i][equal_loc + 1], ft_strlen(temp[i]) - equal_loc);
		write(1, "\"\n", 2);
		++i;
	}
	free_darray(temp);
	return (0);
}

int	export(char	**arg, t_cmd_info *shell_info)
{
	int	ac;

	ac = count_arg(arg);
	if (ac == 1)
		shell_info->last_exit = export_print(shell_info->global_var);
	else
		shell_info->last_exit = add_var(arg, shell_info->global_var);
	return (0);
}