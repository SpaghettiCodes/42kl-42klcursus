#ifndef RUSH02_H
# define RUSH02_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct Dictionary{
	int value;
	char *definition;
	struct Dictionary *next;
} dictionary;

typedef struct WORDS{
	char	*word;
	struct WORDS *next;
} words;

int		ft_strlen(char *str);
char	**ft_split(char *str);

#endif
