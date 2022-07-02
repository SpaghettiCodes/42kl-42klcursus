#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size){
	char	*result;
	size_t	i;

	result = (char *) malloc (nitems * size);
	if (!result)
		return 0;
	i = 0;
	while (i < nitems){
		result[i++] = 0;
	}
	return ((void *) result);
}
