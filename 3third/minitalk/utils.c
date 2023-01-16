#include "endmysuffering.h"

int ft_strlen(char *str)
{
	int ret;

	ret = 0;
	if (!str)
		return (0);
	while (str[ret])
		ret++;
	return(ret);
}

char *ft_append(char *src, char *dest)
{
	char *ret;
	int i;
	int j;

	ret = malloc (ft_strlen(src) + ft_strlen(dest) + 1);
	i = 0;
	j = 0;
	while (dest && dest[i])
	{
		ret[i] = dest[i];
		i++;
	}
	while (src && src[j])
	{
		ret[i] = src[j];
		j++;
		i++;
	}
	ret[i] = 0;
	if (dest)
		free(dest);
	return (ret);
}

int ft_print(char *str)
{
	int	ret;
	ret = -1;

	while(str[++ret])
		write(1, &str[ret], 1);

	return (ret);
}

int ft_num(int num)
{
	char ret;
	if (num >= 10)
		ft_num(num/10);
	ret = (num % 10) + '0';
	write(1, &ret, 1);
}

int ft_atoi(char *nbr)
{
	int ret;

	printf("in atoi\n");
	while (*nbr == ' ')
		nbr++;
	ret = 0;
	while (*nbr <= '9' && *nbr >= '0')
	{
		ret = (ret * 10) + (*nbr - '0');
		nbr++;
	}
	printf("nbr returned: %d\n", ret);
	return (ret);
}
