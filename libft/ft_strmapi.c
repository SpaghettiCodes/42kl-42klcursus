#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char)){
	int		slen;
	char	*mapped;
	int		i;

	if (s) {
		slen = ft_strlen((char *) s);
		if ((mapped = (char *) malloc ((slen + 1) * sizeof(char)))) {
			i = -1;
			while (s[++i] != '\0')
				mapped[i] = f(i, s[i]);
			mapped[i] = '\0';
			return (mapped);
		}
	}
	return 0;
}

