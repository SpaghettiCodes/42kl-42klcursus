#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n){
	int			i;
	int			srclen;
	char		*d;
	const char	*s;

	if (n && dest && src){
		d = (char *) dest;
		s = (const char *) src;
		srclen = ft_strlen((char *) src);
		if (n > srclen)
			i = (int) srclen;
		else
			i = (int) n;
		d[i--] = '\0';
		while (i >= 0){
			d[i] = s[i];
			i--;
		}
	}
	return (dest);
}

