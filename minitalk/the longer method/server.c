#include "endmysuffering.h"

int	ft_bitconv(char *bits)
{
	int	bitcount;
	int ret;
	bitcount = 9;

	ret = 0;
	while (--bitcount >= 0)
	{
		if (bits[bitcount] == '0')
			ret = (ret * 2) + 0;
		else if (bits[bitcount] == '1')
			ret = (ret * 2) + 1;
	}
	printf("return value = %d\n", ret);
	return (ret);
}

int	ft_putchar(char help)
{
	printf("%c", help);
}

void	signal_get(int signal)
{
	static char	*bits;
	int		print;

	printf("got signal\n");
	printf("bits currently: %s\n", bits);
	if (signal == BIT1)
		bits = ft_append("1", bits);
	else if (signal == BIT0)
		bits = ft_append("0", bits);
	if (ft_strlen(bits) == 8)
	{
		printf("got a character!\n");
		print = ft_bitconv(bits);
		printf("print = %d", print);
		ft_putchar(print);
		free(bits);
		bits = 0;
	}
	return ;
}

int main(int what, char **the)
{
	ft_num(getpid());
	ft_print("\n");
	signal(SIGUSR1, signal_get);
	signal(SIGUSR2, signal_get);

	while(1)
		pause();
}
