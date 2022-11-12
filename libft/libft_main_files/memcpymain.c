#include <stdio.h>
#include <string.h>
#include "ft_memcpy.c"
#include "ft_strlen.c"
#include "ft_memmove.c"

int main()
{
    char str[100] = "Learningisfun";
    char str2[100] = "Learningisfun";
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
