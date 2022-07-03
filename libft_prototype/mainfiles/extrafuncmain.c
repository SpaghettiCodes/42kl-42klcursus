#include <string.h>
#include <stdio.h>
#include "ft_strjoin.c"
#include "ft_strtrim.c"
#include "ft_strmapi.c"


#include <stdio.h>

char	idk(unsigned int i, char y){
	return ('z');
}

int main(){
	char const s[] = "Testing123PizzaYumPasta";
	char *b = ft_substr(s, 13, 100);
	printf("%s ", b);
	if (b)
		printf("Word length %d\n", strlen(b));
	printf("\n");


	char *s1 = "I am the ";
	char *s2 = "storm that is approaching";
	char *s1s2;
	s1s2 = ft_strjoin(s1, s2);
	printf("%s\n\n", s1s2);

	char const *s3 = "aaaaaaaaaaaaawwww";
	char *set = "why";
	char *trimmed;
	trimmed = ft_strtrim(s3,set);
	printf("%s\n", trimmed);

	char const *s = "";
	printf("%s\n",s);
	char *b = ft_strmapi(s, idk);
	printf("%s\n",b);
}
