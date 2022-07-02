#include "ft_strdup.c"
#include<stdio.h>
#include<string.h>

int main()
{
    char source[] = "testestest123456";
    char* target = ft_strdup(source);

    printf("%s", target);
    return 0;
}
