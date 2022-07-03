#include "libft.h"

size_t	ft_strlcpy(char * dst, const char * src, size_t dstsize){
	int		srclen;
	size_t	z;

	srclen = 0;
	if (!src || !dst) // check if src and dst is null, not sure if needed, test on imac
		return (0);
	while (src[srclen] != '\0')
		srclen++;
	if (dstsize) {
		z = 0;
		while(z < (dstsize - 1) && src[z] != '\0'){
			dst[z] = src[z];
			z++;
		}
		dst[z] = '\0';
	}
	return (srclen);
}
