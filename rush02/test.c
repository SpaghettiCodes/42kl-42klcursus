// #include <stdio.h>
// #include <stdlib.h>

// int ft_strlen(char *str)
// {
// 	int i;
// 	for (i = 0; str[i]; i++){};
// 	return (i);
// }
// char *append(char *dest, char *source)
// {
// 	char *ret;
// 	int	i;
// 	int j;

// 	ret = malloc(sizeof(char) * (ft_strlen(dest) + ft_strlen(source) + 1));
// 	i = -1;
// 	while(source[++i])
// 		ret[i] = source[i];
// 	j = -1;
// 	while(dest[++j])
// 		ret[i++] = dest[j];
// 	ret[i] = '\0';
// 	// free(dest);
// 	return (ret);
// }

// int main()
// {
// 	char *source = "abcdef\0";
// 	char *dest = "01234567\0";
// 	printf("%s\n", dest);
// 	dest = append(dest, source);
// 	printf("%s\n", dest);
// }
