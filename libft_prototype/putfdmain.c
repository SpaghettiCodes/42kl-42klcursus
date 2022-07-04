#include "libft.h"
#include "ft_putchar_fd.c"
#include "ft_putstr_fd.c"
#include "ft_putendl_fd.c"

int main(){
	int fd = open ("putfdmain.txt",  O_RDWR | O_CREAT );
	ft_putendl_fd("the heck", fd);
}
