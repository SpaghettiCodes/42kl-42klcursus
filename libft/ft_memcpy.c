#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n){
	size_t		i;
	char		*d;
	const char	*s;

	if (n && dest && src){
		d = (char *) dest;
		s = (const char *) src;
		i = 0;
		while (i < n || s[i] == '\0'){
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
