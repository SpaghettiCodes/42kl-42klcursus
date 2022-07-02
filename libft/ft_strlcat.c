#include "libft.h"
#include "ft_strlen.c"

size_t	ft_strlcat(char *dest, const char *src, size_t size){
	int		i;
	size_t	destlen;
	size_t	srclen;
	int		j;


	destlen = ft_strlen(dest);
	srclen = ft_strlen((char *) src);
	if (size == 0)
		return (srclen);
	j = 0;
	i = destlen;
	while (i < (size - 1) || src[j] == '\0'){
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (destlen + srclen);
}
