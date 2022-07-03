#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size){
	void	*result;

	if (!nitems || !size)
		return 0;
	result = malloc (nitems * size);
	if (!result)
		return 0;
	ft_bzero(result, (nitems * size));
	return (result);
}
