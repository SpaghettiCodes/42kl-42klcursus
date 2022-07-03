#include "libft.h"

int	ft_isprint(int arg){
	if (arg == 32) // whitespace
		return (64);
	if ((arg >= 33 && arg <= 47) || (arg >= 123 && arg <= 126)
		|| (arg >= 58 && arg <= 64) || (arg >= 91 && arg <= 96)) // symbols
		return (16);
	if (arg >= 65 && arg <= 90) // big letter
		return (1);
	if (arg >= 97 && arg <= 122) // small letter
		return (2);
	if (arg >= 48 && arg <= 57) // numbers
		return (4);
	return (0);
}
