#include "libft.h"

int	ft_isalnum(int arg){
	return ((arg >= 'A' && arg <= 'Z') || (arg >= 'a' && arg <= 'z')
		|| (arg >= '0' && arg <= '9')) ;
}
