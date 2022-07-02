#include "libft.h"
#include "ft_strlen.c"

char *ft_substr(char const *s, unsigned int start, size_t len){
	char	*substr;
	int		i;

	if (ft_strlen((char *) s) < start)
		return(0);
	substr = (char *) malloc ((len + 1) * sizeof(char));
	if (substr && len && s){
		i = -1;
		while (++i < (int) len && s[start]){
			substr[i] = s[start];
			start++;
		}
		substr[i] = '\0';
		return (substr);
	}
	return (0);
}
