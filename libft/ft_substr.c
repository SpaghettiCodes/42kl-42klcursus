#include "libft.h"

#include "ft_strlen.c"
#include "ft_strdup.c"

char *ft_substr(char const *s, unsigned int start, size_t len){
	char	*substr;
	int		i;

	if (s && start < ft_strlen((char *) s)){
		if (!len)
			return (ft_strdup(""));
		substr = (char *) malloc ((len + 1) * sizeof(char));
		if (substr){
			i = -1;
			while (++i < (int) len && s[start]){
				substr[i] = s[start];
				start++;
			}
			substr[i] = '\0';
			return (substr);
		}
	}
	return (0);
}
