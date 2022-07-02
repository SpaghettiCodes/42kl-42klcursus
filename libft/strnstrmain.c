#include <stdio.h>
#include "ft_strnstr.c"
#include <string.h>

char *in = "la da doo a da now here comes the stackdummy ok there it was.\n";

int main(){
    printf("My Fucn- found: %s\n", ft_strnstr(in, "oo", 10));
    printf("My Fucn- found: %s\n", ft_strnstr(in, "the", 5));
    printf("My Fucn- found: %s\n", ft_strnstr(in, "stack", strlen(in)));
    printf("My Fucn- found: %s\n", ft_strnstr(in, "stack", 0));
	printf("My Fucn- found: %s\n", ft_strnstr(in, "", strlen(in)));
    printf("lmao sysfunc has no strnstr\n");
    return 0;
}
