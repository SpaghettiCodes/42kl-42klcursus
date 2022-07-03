#include "libft.h"

char *ft_strdup(const char *s){
	char	*dup;
	int		i;
	int		slen;

	if (!s)
		return (0);
	slen = ft_strlen((char *) s);
	dup = (char *) malloc ((slen + 1) * sizeof(char));
	if (!dup)
		return (0);
	i = -1;
	while (s[++i])
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}
