#include "libft.h"
#include <stdio.h>

#include "ft_substr.c"

char **inputwords(char const *s, char c, char **splitted, int word){
	printf("in iputwords\n");
	int	i;
	int	count_word;
	int	letter;
	int	start;

	count_word = 0;
	letter = 0;
	i = -1;
	start = 0;
	while (count_word < word){
		if ((s[++i] == c || (s[i+1] == '\0' && s[i] != c) && ++letter) && letter != 0){
			printf("start = %d, letter = %d\n", start, letter);
			splitted[count_word++] = ft_substr(s, (start), letter);
			start = i+1;
			letter = 0;
			continue;
		} else if (s[i] == c && letter == 0 && ++start)
			continue;
		letter++;
	}
	return (splitted);
}

char **countletters(char const *s, char c, int word){
	char	**out;
	int		i;
	int		letter;

	i = -1;
	letter = 0;
	out = (char **) malloc ((word + 1) * sizeof(char *));
	word = 0;
	while (1) {
		if ((s[++i] == c || (s[i] == '\0' && s[i-1] != c)) && letter != 0){
			printf("word = %d, letters = %d\n", word, letter);
			out[word++] = ((char *) malloc ((letter + 1) * sizeof(char *)));
			letter = 0;
			if (s[i] == '\0')
				break;
			continue;
		} else if (s[i] == c && letter == 0)
			continue;
		printf("%c\n", s[i]);
		letter++;
	}
	return (out);
}

int	countwords(char const *s, char c){
	int	i;
	int	word;

	i = 0;
	if (s[0] != c)
		word = 1;
	else
		word = 0;
	while (s[++i]){
		if (s[i] != c && s[i-1] == c){
			printf("%c \n", s[i]);
			word++;
		}
	}
	return (word);
}

char **ft_split(char const *s, char c){
	//i have ptsd LMAO
	char **splitted;
	int	word;

	if (s){
		if (s[0] == '\0')
			return (0);
		word = countwords(s, c);
		printf("words: %d\n", word);
		splitted = (char **) malloc ((word + 1) * sizeof(char *));
		splitted = countletters(s, c, word);
		inputwords(s, c, splitted, word);
		splitted[word] = 0;
	}
	return (splitted);
}

int main(){
	char const *s = "pen pineapple apple pen";
	char **test;
	test = ft_split(s, 'p');
	for (int i = 0; test[i]; i++){
		printf("%s ", test[i]);
	}
}
