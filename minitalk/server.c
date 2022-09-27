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
	printf("%c", ret);
	return (1);
}

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
