#include <stdio.h>
#include <string.h>
#include "ft_strchr.c"

int main ()
{
    const char str[] = "Use strchr() function in C.";
    const char ch = 's'; // it is searched in str[] array
    char *ptr; // declare character pointer ptr

    printf (" Original string is: %s \n", str);
    // use strchr() function and pass str in which ch is to be searched
    ptr = ft_strchr( str, ch);
    printf (" The first occurrence of the '%c' in '%s' string  is: '%s' ", ch, str, ptr);
    return 0;
}
