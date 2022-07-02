#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n){
	const char	*s;
	size_t		i;

	s = (char *) str;
	i = 0;
	if (n) {
		while (i < n){
			if (s[i] == c)
				return ((void *) &s[i]);
			i++;
		}
	}
	return 0;
}
