#include "minishell.h"

int	eprint(char *element, char *msg)
{
	write(2, "Terminal Complained : ", 23);
	write(2, "(", 1);
	if (element)
		write(2, element, ft_strlen(element));
	write(2, ")", 1);
	write(2, " ", 1);
	if (msg)
		write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return(11 + ft_strlen(element) + ft_strlen(msg));
}