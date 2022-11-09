#include "endmysuffering.h"

int	senddasignal(int pid, char *send)
{
	int	i;
	int	count;
	char	send_char;

	i = -1;
	while(send[++i])
	{
		send_char = send[i];
		count = -1;
		while (++count != 8)
		{
			if (send_char % 2 == 1)
				kill(pid, BIT1);
			else
				kill(pid, BIT0);
			send_char /= 2;
		}
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
	senddasignal(pid, send);

	while(1)
		pause();
}
