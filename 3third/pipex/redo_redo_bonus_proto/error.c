#include "pipex.h"

int	eprint(char *element, char *msg)
{
	write(2, "pipex: ", 8);
	if (element)
		write(2, element, ft_strlen(element));
	write(2, ": ", 2);
	if (msg)
		write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return(11 + ft_strlen(element) + ft_strlen(msg));
}