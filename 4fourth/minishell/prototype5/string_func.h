#ifndef FT_SPLIT_H
#define FT_SPLIT_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int		ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_substr2(char const *s, unsigned int start, unsigned int end);
char	**ft_split(char const *s, char c);

#endif