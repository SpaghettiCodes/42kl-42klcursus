#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*)){
	int	i;

	i = -1;
	while (s[++i] != '\0')
		f(i, &s[i]);
}
