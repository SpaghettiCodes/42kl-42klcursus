#include "endmysuffering.h"



int	what(int signal)
{
	static char *bits;
	int	bitcount;

	bitcount = 0;
	if (signal == SIGUSR1)
		bits = ft_append("1", bits);
	else if (signal == SIGUSR2)
		bits = ft_append("0", bits);
	bitcount++;
	if (bitcount == 8)
	{
		ft_print(ft_bitconv(bits));
		free(bits);
		bits = 0;
		bitcount = 0;
	}
	return (1);
}

int main(int what, char **the)
{
	ft_num(getpid());
	signal(SIGUSR1, signal);
	signal(SIGUSR2, signal);

	while(1)
		sleep(10);
}
