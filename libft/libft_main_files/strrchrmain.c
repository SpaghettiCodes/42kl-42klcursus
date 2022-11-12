#include <stdio.h>
#include <string.h>
#include "ft_strrchr.c"

int main () {
   int len;
   const char str[] = "AWIdpiWANDioNAWodbawbDPwaopdh";
   const char ch = 'a';
   char *ret;

   ret = strrchr(str, ch);

   printf("Sys Fun: String after |%c| is - |%s|\n", ch, ret);
   ret = ft_strrchr(str, ch);

   printf("My Fun: String after |%c| is - |%s|\n", ch, ret);

   return(0);
}
