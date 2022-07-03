#include "libft.h"

int	ft_inset(char c, char const *set){
	int	i;

	i = -1;
	while (set[++i] != '\0')
		if (set[i] == c)
			return 1;
	return 0;
}
char	*ft_strtrim(char const *s1, char const *set){
	char	*trimmed;
	int		begin;
	int		size;
	int		end;

	if (s1) {
		if (!set)
			return (ft_strdup(s1));
		begin = -1;
		if (s1){
			size = ft_strlen((char *) s1);
			end = size;
			while (ft_inset(s1[++begin], set) == 1)
				size--;
			if (begin != end){
				while (ft_inset(s1[--end], set) == 1)
					size--;
				trimmed = ft_substr(s1, begin, size);
			} else
				trimmed = ft_strdup("");
			if (trimmed)
				return (trimmed);
		}
	}
	return 0;
}
