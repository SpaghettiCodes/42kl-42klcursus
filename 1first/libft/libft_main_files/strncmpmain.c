#include <stdio.h>
#include <string.h>
#include "ft_strncmp.c"

int main () {
   char str1[15];
   char str2[15];
   int ret;

   strcpy(str1, "ABCDEF");
   strcpy(str2, "ABcDEF");

   ret = strncmp(str1, str2, 10);

	printf("Sys Fun: %d\n", ret);
   ret = ft_strncmp(str1, str2, 10);

	printf("My Fun: %d\n", ret);
   return(0);
}
