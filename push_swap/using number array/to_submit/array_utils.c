#include "push_swap.h"

int	str_len(char *str)
{
	int	counter;

	if (!str)
		return (0);
	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

char	*str_dup(char *str)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * (str_len(str) + 1));
	i = -1;
	while (str[++i])
		ret[i] = str[i];
	ret[i] = 0;
	return (ret);
}

int	*copy(int *source, int source_size)
{
	int	i;
	int	*ret;

	i = -1;
	ret = malloc(sizeof(int) * source_size);
	while (++i < source_size)
		ret[i] = source[i];
	return (ret);
}