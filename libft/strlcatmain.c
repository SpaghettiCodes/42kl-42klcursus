#include <stdio.h>
#include <string.h>
#include "ft_strlcat.c"
#include "ft_strlcpy.c"

int main()
{
    char first[] = "12345678";
    char last[] = "abcdefg";
    int r;
    int size = 10;
    char buffer[size];

	int i = -1;
	while (first[++i] != '\0')
		buffer[i] = first[i];
	buffer[i] = '\0';
	printf("Before: ");
	puts(buffer);
    r = ft_strlcat(buffer,last,size);

	printf("After: ");
    puts(buffer);
    printf("Value returned: %d\n",r);
    if( r > size )
        puts("String truncated");
    else
        puts("String was fully copied");
	printf("String length = %d\n", strlen(buffer));
    return(0);
}
