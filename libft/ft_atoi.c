#include "libft.h"

int	ft_isspace(char c){
	return ((c == 32) || (c >= 9 && c <= 13));
}

int	ft_atoi(const char *str){
	int	result;
	int	negative;
	int	i;

	i = 0;
	result = 0;
	negative = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' && ++i)
		negative = -1;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9'){
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * negative);
}
