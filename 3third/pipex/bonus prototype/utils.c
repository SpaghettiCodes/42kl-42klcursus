#include "pipex.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[i] == str2[i])
	{
		if (!str2[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strcmp_nl(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[i] == str2[i])
	{
		if (str1[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}
