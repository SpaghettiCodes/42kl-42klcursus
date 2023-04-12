#include "minishell.h"

int list_env(t_val *variables)
{
	while (variables)
	{
		if (variables->type != SELF)
		{
			write(1, variables->theline, ft_strlen(variables->theline));
			write(1, "\n", 1);
		}
		variables = variables->next;
	}
	return (0);
}