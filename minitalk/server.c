#include "endmysuffering.h"

int	ft_putchar(char help)
{
	write(1, &help, 1);
}

void	signal_get(int signal)
{
	static int	count;
	static int	bit;
	int		print;

	count = count + 1;
	printf("got signal\n");
	printf("bits currently: %d\n", bit);
	if (signal == BIT1)
		bit = (bit * 2) + 1;
	else if (signal == BIT0)
		bit = (bit * 2) + 0;
	if (count == 8)
	{
		printf("got a character!\n");
		printf("print = %d", bit);
		ft_putchar(bit);
		count = 0;
		bit = 0;
	}
	return ;
}

int main(int what, char **the)
{
	int bit;
	int	count;

	ft_num(getpid());
	ft_print("\n");
	signal(SIGUSR1, signal_get);
	signal(SIGUSR2, signal_get);

	while(1)
		pause();
}
