#include <stdio.h>
#include "ft_bzero.c"

int main(){
	int i;
	char a[] = {1,2,3,4,5};

	printf("\n");
	for( i=0 ; i < 10 ; i++ ) {
      printf("%d ",a[i]);
   	}
	ft_bzero(a, 4);
	printf("\n");
	for( i=0 ; i < 10 ; i++ ) {
      printf("%d ",a[i]);
   	}
}
