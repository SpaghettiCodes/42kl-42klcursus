#include "minishell.h"

int unset_variables(char **arg, t_val **val)
{
	t_val		*prev;
	t_val		*current;
	int			i;

	i = 1;
	// unset EVERY SINGLE VAL
	// if (!ft_strcmp(arg[1], "all"))
	// {
	// 	(*val) = NULL;
	// 	return 0;
	// }
	while (arg[i])
	{
		current = (*val);
		prev = NULL;
		while (current)
		{
			if (!ft_strncmp(current->theline, arg[i], current->equalloc))
				break;
			prev = current;
			current = current->next;
		}
		if (current)
		{
			if (prev)
				prev->next = current->next;
			else
				(*val) = current->next;
			free_val_content(current);
			free(current);
		}
		++i;
	}
	return (0);
}