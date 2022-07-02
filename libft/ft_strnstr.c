#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len){
	int	i;
	int	j;
	int firstseen;

	i = 0;
	if (len) {
		if (little[0] == '\0')
			return ((char *) big);
		while (big[++i] != '\0' && i < (int) len){
			if (big[i] == little[0]){
				firstseen = i;
				j = 0;
				while (big[++i] == little[++j]){
					if (little[j+1] == '\0')
						return ((char *) &big[firstseen]);
				}
				i = firstseen + 1;
			}
		}
	}
	return (0);
}
