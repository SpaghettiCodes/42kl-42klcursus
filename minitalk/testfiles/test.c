// #include "endmysuffering.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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

char *convtobits(char *str)
{
	int i;
	int j;
	char *ret;
	char bits[9];

	i = -1;
	ret = 0;
	bits[8] = '\0';
	while (str[++i])
	{
		j = -1;
		while ((++j < 8))
		{
			bits[j] = (str[i] % 2) + '0';
			str[i] = str[i] / 2;
		}
		ret = ft_append(bits, ret);
	}
	ret = ft_append("\0", ret);
	return (ret);
}

int main()
{
	char *test = "\1\0";
	char *test2;
	test2 = convtobits(test);
	printf("%s", test2);
}
