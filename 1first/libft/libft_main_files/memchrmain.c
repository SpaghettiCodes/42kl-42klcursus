#include <stdio.h>
#include <string.h>
#include "ft_memchr.c"

int main () {
   const char *str = "ihadowibdoibaoibxwanidiqwe";
   const char ch = 'x';
   char *ret;

   ret = memchr(str, ch, 14);

   printf("Sys Func: String after |%c| is - |%s|\n", ch, ret);
   ret = ft_memchr(str, ch, 14);

   printf("My Func: String after |%c| is - |%s|\n", ch, ret);

   return(0);
}
