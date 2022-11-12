#include "rush02.h"

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while(str[++i]){};
	return (i);
}

char	*ft_substr(char *s, unsigned int start, unsigned int end)
{
	char	*substr;
	int		i;

	substr = (char *) malloc (((end - start) + 2) * sizeof(char));
	if (!substr)
		return (0);
	i = 0;
	while ((start <= end) && s[start])
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

void	clearall(words **splitted)
{
	words *current;
	words *temp;
	current = *splitted;
	while (current)
	{
		temp = current->next;
		if (current->word)
			free(current->word);
		free (current);
		current = temp;
	}
}

int	count_elem(words *splitted)
{
	printf("in count_elem again\n");
	int i;
	words *current;

	i = 0;
	current = splitted;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i + 1);
}


char	*ft_strdup(char *s)
{
	char	*dup;
	int		i;
	int		slen;

	slen = ft_strlen(s);
	dup = (char *) malloc ((slen + 1) * sizeof(char));
	if (!dup)
		return (0);
	i = -1;
	while (s[++i])
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}

char **convert(words *splitted)
{
	printf("converting..\n");
	char **ret;
	int i;
	words *current;

	ret = (char **) malloc (count_elem(splitted) * (sizeof (char *)));
	printf("malloced\n");
	current = splitted;
	i = -1;

	while (current && current->word)
	{
		ret[++i] = ft_strdup(current->word);
		current = current->next;
	}
	ret[++i] = 0;

	printf("done converting clearing...\n");
	clearall(&splitted);
	return (ret);
}

char **ft_split(char *str)
{
	printf("in ft_split\n");
	words *splitted;
	words *current;
	int	start;
	int	end;
	int length;

	start = 0;
	end = 0;
	length = ft_strlen(str);
	splitted = malloc(sizeof (words));
	current = splitted;
	while (end <= length)
	{
		if (str[end] == '\n' || str[end] == '\0')
		{
			if ((((end - 1) - start) + 1) > 0)
			{
				current->word = ft_substr(str, start, (end - 1));
				current->next = malloc ((sizeof(words)));
				current = current->next;
			}
			start = end + 1;
		}
		end++;
	}
	current->word = 0;
	current->next = 0;
	printf("done planning\n");
	return (convert(splitted));
}

// int main()
// {
// 	char **test;
// 	char test2[] = "0: zero\n1: one\n2: two\n3: three\n4: four\n5: five\n6: six\n7: seven\n8: eight\n9: nine\n10: ten\n11: eleven\n12: twelve\n13: thirteen\n14: fourteen\n15: fifteen\n16: sixteen\n17: seventeen\n18: eighteen\n19: nineteen\n20: twenty\n30: thirty\n40: forty\n50: fifty\n60: sixty\n70: seventy\n80: eighty\n90: ninety\n100: hundred\n1000: thousand\n1000000: million\n1000000000: billion\n1000000000000: trillion\n1000000000000000: quadrillion\n1000000000000000000: quintillion\n1000000000000000000000: sextillion\n1000000000000000000000000: septillion\n1000000000000000000000000000: octillion\n1000000000000000000000000000000: nonillion\n1000000000000000000000000000000000: decillion\n1000000000000000000000000000000000000: undecillion";
// 	test = ft_split(test2);
// 	for (int i = 0; test[i]; i++)
// 	{
// 		printf("%s\n", test[i]);
// 	}
// }
