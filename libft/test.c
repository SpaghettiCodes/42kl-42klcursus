#include <stdio.h>

int main(){
	printf("255 in bytes \n");
	int a = 255;
	unsigned char *b = (unsigned char *) &a;
	for (int i = 0; i < 4; b++, i++){
		printf("%d ",*b);
	}

	printf("\n256 in bytes \n");
	int e = 256;
	unsigned char *f = (unsigned char *) &e;
	for (int i = 0; i < 4; f++, i++){
		printf("%d ",*f);
	}
}
