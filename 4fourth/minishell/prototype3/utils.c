#include "minishell.h"

int	search_element(char *input, char to_search, size_t start, size_t end)
{
	while (start <= end && input[start])
	{
		if (input[start] == to_search)
			return (start);
		start++;
	}

	return (-1);
}