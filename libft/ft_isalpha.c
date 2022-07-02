#include "libft.h"

int	ft_isalpha(int arg){
	if ((arg >= 'A' && arg <= 'Z'))
		return (1); // an alphabet
	if ((arg >= 'a' && arg <= 'z'))
		return (2);
	return (0) ; // not an alphabet
}
