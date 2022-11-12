#include <stdio.h>
#include "libft.h"
#include "ft_itoa.c"

int main(){
	for (int i = 0; i < 999; i++)
		printf("%s\n", ft_itoa(i));
	for (int i = -999; i < 0; i++)
		printf("%s\n", ft_itoa(i));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483648));
}
