#include "ft_memset.c"
#include <stdio.h>

#define  BUF_SIZE  20

int main () {
   char str[] = "This is string.h library function";

   puts(str);

   ft_memset(str,'$',7);
   puts(str);

   return(0);
}
