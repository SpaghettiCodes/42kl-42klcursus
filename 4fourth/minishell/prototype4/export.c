#include "minishell.h"

int	add_var(char **arg, t_val *global_variable)
{
	int		i;
	int		equal_loc;
	t_val	*searcher;

	i = 1;
	while (arg[i])
	{
		equal_loc = search_character(arg[i], '=', 0, -1);
		if (equal_loc == -1)
			equal_loc = ft_strlen(arg[i]);
		searcher = search_variable(arg[i], global_variable);
		if (!searcher)
		{
			searcher = add_back_variable(global_variable);
			fill_val(searcher->next, 1, ft_strdup(arg[i]), equal_loc);
		}
		else
		{
			if (equal_loc = ft_strlen(arg[i]))
				continue;
			free_current_val(searcher);
			fill_val(searcher, 1, ft_strdup(arg[i]), equal_loc);
		}
		++i;
	}
	return (0);
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
		write(1, temp[i], ft_strlen(temp[i]));
		write(1, "\n", 1);
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