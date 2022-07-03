#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2){
	char	*joined;
	int		s1len;
	int		s2len;

	if (s1 && s2){
		s1len = ft_strlen((char *) s1);
		s2len = ft_strlen((char *) s2);
		if ((joined = (char *) malloc ((s1len + s2len + 1) * sizeof(char)))){
			ft_strlcpy(joined, s1, (s1len + 1));
			ft_strlcpy((joined + s1len), s2, (s2len + 1));
			return (joined);
		}
	}
	return (0);
}
