#include "minishell.h"

// appends str2 at the back of str1 -- frees str1 and null terminate the appeneded string
char	*append(char *str1, char *str2)
{
	char	*ret;
	int		i;
	int		j;

	ret = malloc (ft_strlen(str1) + ft_strlen(str2) + 1);
	i = -1;
	while (str1[++i])
		ret[i] = str1[i];
	j = 0;
	while (str2[j])
	{
		ret[i] = str2[j];
		j++;
		i++;
	}
	ret[i] = 0;
	free(str1);
	return (ret);
}

// similar with append BUT does not free str1 and returns a malloced string
char	*n_append(char *str1, char *str2)
{
	char	*ret;
	int		i;
	int		j;

	ret = malloc (ft_strlen(str1) + ft_strlen(str2) + 1);
	i = -1;
	while (str1[++i])
		ret[i] = str1[i];
	j = 0;
	while (str2[j])
	{
		ret[i] = str2[j];
		j++;
		i++;
	}
	ret[i] = 0;
	return (ret);
}