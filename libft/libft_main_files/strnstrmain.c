#include <stdio.h>
#include "ft_strnstr.c"
#include <string.h>

// char *in = "test test woo woo waa\n";

// int main(){
//     printf("My Fucn- found: %s\n", ft_strnstr(in, "w", 10));
//     printf("My Fucn- found: %s\n", ft_strnstr(in, "the", 5));
//     printf("My Fucn- found: %s\n", ft_strnstr(in, "stack", strlen(in)));
//     printf("My Fucn- found: %s\n", ft_strnstr(in, "stack", 0));
// 	printf("My Fucn- found: %s\n", ft_strnstr(in, "", strlen(in)));
//     printf("lmao sysfunc has no strnstr\n");
//     return 0;
// }

int main(void)
{
    char s1big[100] = "test test woo woo waa";
    char s1little[4] = "waa";

    char *ptr1 = ft_strnstr(s1big, s1little, 100);

    printf("Big   : (%s)\n", s1big);
    printf("Little: (%s)\n", s1little);
    printf("My    : (%s)\n", ptr1);

    return (0);

}
