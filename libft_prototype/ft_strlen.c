#include "libft.h"

int	ft_strlen(char *arg){
	int	i;

	i = 0;
	while (arg[i] != '\0')
		i++;
	return (i);
}
