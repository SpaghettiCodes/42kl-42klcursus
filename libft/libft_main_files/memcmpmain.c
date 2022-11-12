#include <stdio.h>
#include <string.h>
#include "ft_memcmp.c"

int main () {
   char str1[15] = "abcDEF";
   char str2[15] = "abceef";
   int ret;

   ret = memcmp(str1, str2, 4);
	printf("Sys fun: %d\n", ret);

	ret = ft_memcmp(str1, str2, 4);
	printf("My fun: %d\n", ret);

   return(0);
}
