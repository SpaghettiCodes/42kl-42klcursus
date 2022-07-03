#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n){
	int			i;
	size_t		srclen;
	char		*d;
	const char	*s;

	if (n && dest && src){
		d = (char *) dest;
		s = (const char *) src;
		srclen = (size_t) ft_strlen((char *) src);
		if (n > srclen)
			i = (int) srclen - 1;
		else
			i = (int) n - 1;
		while (i >= 0){
			d[i] = s[i];
			i--;
		}
	}
	return (dest);
}

