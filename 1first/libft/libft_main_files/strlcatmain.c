#include <stdio.h>
#include <string.h>
#include "ft_strlen.c"
#include "ft_strlcat.c"
#include "ft_strlcpy.c"

int test(size_t f(char *, const char *, size_t))
{
    char first[] = "12345678";
    char last[] = "abcdefghijk";
    int r;
    int size = 5;
    char buffer[size];

	int i = -1;

	while (first[++i] != '\0')
		buffer[i] = first[i];
	buffer[i] = '\0';

	printf("Before: ");
	puts(buffer);
    r = f(buffer,last,size);

	printf("After: ");
    puts(buffer);
    printf("Value returned: %d\n",r);
    if( r > size )
        puts("String truncated");
    else
        puts("String was fully copied");
	printf("String length = %lu\n", strlen(buffer));
    return(0);
}

int main(){
	printf("MyFunction\n");
	test(strlcat);
	printf("\n\nSystem Function\n");
	test(ft_strlcat);
	return 0;
}
