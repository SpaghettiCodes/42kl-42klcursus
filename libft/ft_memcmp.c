#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n){
	const char	*s1;
	const char	*s2;
	size_t		i;

	if (str1 && str2 && n) {
		s1 = (const char *) str1;
		s2 = (const char *) str2;
		i = 0;
		while (i < n){
			if (s1[i] != s2[i])
				return ((s1[i] - s2[i]));
			if (s1[i] == '\0' || s2[i] == '\0')
				break;
			i++;
		}
	}
	return 0;
}
