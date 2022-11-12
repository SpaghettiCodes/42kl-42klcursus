
// Sample program to show that memmove() is better than
// memcpy() when addresses overlap.
#include "ft_strlen.c"
#include <stdio.h>
#include <string.h>
#include "ft_memmove.c"
#include "ft_memcpy.c"
int main()
{
    char str[100] = "LearningIsFun";
    char str2[100] = "LearningIsFun";
    char *first, *second;
    first = str;
    second = str2;
    printf("Original string :%s\n ", str);

    // when overlap happens then it just ignore it
    ft_memcpy(first + 8, first, 10);
    printf("memcpy overlap : %s\n ", str);

    // when overlap it start from first position
    ft_memmove(second + 8, second, 10);
    printf("memmove overlap : %s\n ", str2);

    return 0;
}

// int main()
// {
// 	char csrc2[9];
// 	char csrc[] = "Geeksfor";
// 	ft_memmove(csrc2, csrc, 3);
// 	printf("%s", csrc2);
// 	return 0;
// }
