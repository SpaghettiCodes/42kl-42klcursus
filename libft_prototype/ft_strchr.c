#include "libft.h"

char	*ft_strchr(const char *str, int c){
	int	i;

	if (str){
		i = 0;
		while(str[i] != '\0'){
			if (str[i] == c)
				return ((char *) &str[i]);
			i++;
		}
	}
	return (0);
}
