#include "libft.h"
#include "ft_memset.c"

void	ft_bzero(void *str, size_t n){
	ft_memset(str, 0, n);
}
