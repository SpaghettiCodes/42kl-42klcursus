#include "libft.h"
#include <stdio.h>

char *ft_itoaneg(unsigned int n){
	char			*str;
	int				digits;
	unsigned int	n2;

	digits = 1;
	n2 = n;
	while (n2 >= 10){
		n2 /= 10;
		digits++;
	}
	digits++;
	str = (char *) malloc ((digits + 2) * sizeof(int));
	str[0] = '-';
	if (str) {
		str[digits] = '\0';
		while (--digits != 0){
			str[digits] = (n % 10) + '0';
			n /= 10;
		}
		return (str);
	}
	return (0);
}

char *ft_itoa(int n){
	char	*str;
	int		digits;
	int		n2;

	if (n < 0)
		return (ft_itoaneg((unsigned int) (n * -1)));
	digits = 0;
	n2 = n;
	while (n2 >= 10){
		n2 /= 10;
		digits++;
	}
	digits++;
	str = (char *) malloc ((digits + 1) * sizeof(int));
	if (str) {
		str[digits] = '\0';
		while (--digits != -1){
			str[digits] = (n % 10) + '0';
			n /= 10;
		}
		return (str);
	}
	return (0);
}

int main(){
	for (int i = 0; i < 9999; i++)
		printf(" %s -", ft_itoa(i));
	for (int i = -9999; i < 0; i++)
		printf(" %s -", ft_itoa(i));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483648));
}
