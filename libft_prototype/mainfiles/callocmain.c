#include <stdio.h>
#include <stdlib.h>
#include "ft_calloc.c"

int main () {
	int i, n;
	char *a;
	int *b;

	n = 4;

	a = (char *) ft_calloc (n, sizeof(char));
	printf("Char calloc result: ");
	if (!a){
		printf("null get fucked\n");
		return 0;
	}
	for( i=0 ; i < 10 ; i++ ) {
		printf("%d ",a[i]);
	}
	free( a );

	n = 4;
	b = (int *) ft_calloc (n, sizeof(int));
	printf("\nInt calloc result: ");
	if (!b){
		printf("null get fucked\n");
		return 0;
	}
	for( i=0 ; i < 10 ; i++ ) {
		printf("%d ",b[i]);
	}
	free( a );

	return(0);
}
