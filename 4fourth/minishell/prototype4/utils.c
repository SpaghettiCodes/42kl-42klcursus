#include "minishell.h"

int	search_character(char *input, char to_search, size_t start, size_t end)
{
	while (start <= end && input[start])
	{
		if (input[start] == to_search)
			return (start);
		start++;
	}
	return (-1);
}

// compares string up to end NOT INCLUDING END
int	ft_strncmp(char *haystack, char *needle, int word_len)
{
	int	i;

	i = 0;
	if (!haystack || !needle)
		return (-1);
	if (ft_strlen(needle) != word_len)
		return (1);
	while (i < word_len && haystack[i] == needle[i])
		++i;
	if (i == word_len)
		return (0);
	return (1);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (-1);
	while (str1[i] == str2[i])
	{
		if (str1[i] == '\0' && str2[i] == '\0')
			return 0;
		++i;
	}
	return (str1[i] - str2[i]);
}