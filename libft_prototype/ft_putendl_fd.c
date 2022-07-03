#include "libft.h"

void	ft_putendl_fd(char *s, int fd){
	int	i;

	i = -1;
	if (!s)
		return ;
	while (s[++i])
		write(fd, &s[i], 1);
	write(fd, "\n", 1);
}

