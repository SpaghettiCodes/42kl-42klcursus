
#include <stdio.h>

typedef	char	*str;

int	strinstr(str str1, str str2)
{
	int	i;
	int	first_occur;
	int	j;

	i = 0;
	while (str1[i])
	{
		j = 0;
		first_occur = i;
		while (str2[j] == str1[i + j])
		{
			if (!str2[j + 1])
				return (first_occur);
			j++;
		}
		i++;
	}

	return (-1);
}

int main()
{
	int	ret = strinstr("abcdefghijklmnop", "123");
	printf("First appread in: %d\n", ret);
}