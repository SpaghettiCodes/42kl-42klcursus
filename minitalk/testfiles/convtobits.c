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
	char *bits = malloc (sizeof(char) * 9);

	i = -1;
	ret = 0;
	bits[8] = '\0';
	while (str[++i])
	{
		j = -1;
		while (++j < 8)
		{
			bits[j] = (str[i] % 2) + '0';
			str[i] = str[i] / 2;
		}
		ret = ft_append(bits, ret);
	}
	ret = ft_append("\0", ret);
	free(bits);
	return (ret);
}

int	ft_bitconv(char *bits)
{
	int	bitcount;
	int ret;
	bitcount = 9;

	ret = 0;
	while (--bitcount >= 0)
	{
		if (bits[bitcount] == '0')
			ret = (ret * 2) + 0;
		else if (bits[bitcount] == '1')
			ret = (ret * 2) + 1;
	}
	printf("%c", ret);
	return (1);
}

int main()
{
	char *heh;
	heh = malloc (sizeof(char) * 3);
	heh[0] = 'a';
	heh[1] = 'b';
	heh[2] = 0;
	char *bits = convtobits(heh);
	printf("%s\n", bits);
	ft_bitconv(bits);
	ft_bitconv(bits+8);
}
