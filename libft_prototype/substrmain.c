#include "ft_strdup.c"
#include "ft_substr.c"
#include "libft.h"
#include <stdio.h>

int main(){
	char const *s = "0123456789";
	printf("%s\n",ft_substr(s, 2, 1));
}
