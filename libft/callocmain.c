#include <stdio.h>
#include <stdlib.h>
#include "ft_calloc.c"

int main () {
   int i, n;
   char *a;

	n = 5;
   a = (char *) ft_calloc (n, sizeof(int));
   printf("calloc result: ");
   for( i=0 ; i < 10 ; i++ ) {
      printf("%d ",a[i]);
   }
   free( a );

   return(0);
}
