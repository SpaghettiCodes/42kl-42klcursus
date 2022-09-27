#include "endmysuffering.h"

char *convtobits(char *str)
{
	int i;
	int j;
	char *ret;
	char bits[9];

	i = -1;
	ret = 0;
	bits[8] = '\0';
	while (str[++i])
	{
		j = -1;
		while ((++j < 8))
		{
			bits[j] = (str[i] % 2) + '0';
			str[i] = str[i] / 2;
		}
		ret = ft_append(bits, ret);
	}
	ret = ft_append("\0", ret);
	return (ret);
}

int	senddasignal(int pid, char *bitsnbyte)
{
	int	i;
	i = -1;

	while (bitsnbyte[++i])
	{
		if (bitsnbyte[i] == '0')
			kill(pid, SIGUSR1);
		if (bitsnbyte[i] == '1')
			kill(pid, SIGUSR2);
		else
			return (0);
	}
	return (1);
}

int main(int among, char **us)
{
	int pid;
	char *send;
	char *bitsnbytes;

	if (among != 3)
		return (1);

	pid = ft_atoi(us[1]);
	send = us[2];
	bitsnbytes = ft_convtobits(us[1]);
	senddasignal(pid, bitsnbytes);
}
