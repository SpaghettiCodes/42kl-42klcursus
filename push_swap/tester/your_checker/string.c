#include "checker.h"

int	str_cmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while(str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

char *str_dup(char *src)
{
	int		i;
	char	*ret;

	ret = (char *) malloc (str_len(src) + 1);
	i = 0;
	while (src[i])
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	return(ret);
}