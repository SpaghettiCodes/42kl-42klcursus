#include "libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	size_t	i;
	char	*d;

	if (count && dest){
		d = (char *) dest;
		i = 0;
		while (i < count)
			d[i++] = c;
	}
	return (dest);
}
