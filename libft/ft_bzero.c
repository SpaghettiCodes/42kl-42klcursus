#include "libft.h"

void	ft_bzero(void *str, size_t n){
	size_t	i;
	char *s;

	if (n){
		i = 0;
		s = (char *) str;
		while (i < n){
			s[i++] = 0;
		}
	return ;
	}
}
