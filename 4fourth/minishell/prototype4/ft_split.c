#include "string_func.h"

static char	**freeeverything(char **splitted)
{
	int	i;

	i = -1;
	while (splitted[++i])
		free(splitted[i]);
	free(splitted);
	return (0);
}

static char	**inputwords(char const *s, char c, char **splitted, int count_word)
{
	int	i;
	int	j;
	int	start;
	int	let;

	let = 0;
	i = -1;
	start = 0;
	j = 0;
	while (j < count_word)
	{
		if ((s[++i] == c || (s[i + 1] == '\0' && s[i] != c && ++let)) && let)
		{
			splitted[j] = ft_substr(s, start, let);
			if (!splitted[j++])
				return (freeeverything(splitted));
			start = i + 1;
			let = 0;
			continue ;
		}
		else if (s[i] == c && let == 0 && ++start)
			continue ;
		let++;
	}
	return (splitted);
}

static int	countwords(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	if (s[0] != c)
		word = 1;
	else
		word = 0;
	while (s[++i])
	{
		if (s[i] != c && s[i - 1] == c)
			word++;
	}
	return (word);
}

static char	**ft_singlevalues(char const *s, int word)
{
	char	**splitted;

	if (word == 1)
	{
		splitted = (char **) malloc ((2) * sizeof(char *));
		splitted[0] = ft_strdup((char *) s);
		splitted[1] = 0;
	}
	else
	{
		splitted = (char **) malloc (1 * sizeof(char *));
		splitted[0] = 0;
	}
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		word;

	splitted = NULL;
	if (!s)
		return (0);
	if (s[0] == '\0')
		return (ft_singlevalues(s, 0));
	word = countwords(s, c);
	if (c == '\0')
		return (ft_singlevalues(s, 1));
	splitted = (char **) malloc ((word + 1) * sizeof(char *));
	if (!splitted)
		return (0);
	splitted[word] = 0;
	if (!inputwords(s, c, splitted, word))
		return (freeeverything(splitted));
	return (splitted);
}