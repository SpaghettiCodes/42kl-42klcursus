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
			kill(pid, BIT0);
		if (bitsnbyte[i] == '1')
			kill(pid, BIT1);
		printf("sent signal!\n");
		usleep(100);
	}
	printf("done!\n");
	return (1);
}

int main(int among, char **us)
{
	int pid;
	char *send;
	char *bitsnbytes;

	if (among != 3)
		return (1);

	printf("atoi\n");
	pid = ft_atoi(us[1]);
	printf("out of atoi\n");

	printf("pid = %d\n", pid);

	send = us[2];
	bitsnbytes = convtobits(us[2]);
	printf("bits to send = %s\n", bitsnbytes);
	senddasignal(pid, bitsnbytes);

	while(1)
		pause();
}
