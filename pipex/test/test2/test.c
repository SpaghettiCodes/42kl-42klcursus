#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef char *str;
#define STDIN_FD 0
#define STDOUT_FD 1

int	str_len(str str1)
{
	int	i;
	i = 0;

	while(str1[i])
		i++;
	return (i);
}

str append(str str1, str str2)
{
	char	*ret;
	int		i; 
	int		j;

	ret = (char *) malloc (sizeof(char) * (str_len(str1) + str_len(str2) + 1));
	i = -1;
	while (str1 && str1[++i])
		ret[i] = str1[i];
	j = 0;
	while (str2 && str2[j])
	{
		ret[i] = str2[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}

int main(int ac, char *av[], char *envp[])
{
	int i = -1;
	int	filedesc = open("outfile", O_CREAT | O_WRONLY);
	while (envp[++i])
		printf("%s\n", envp[i]);

	// str binaryPath = "/usr/bin/\0";
	// str command = "ls\0";
	/ dup2(filedesc, STDOUT_FD);
	// printf("envp:\n");
	// for (int i = 0; envp[i]; i++)
	// 	printf("%s\n", envp[i]);
	// printf("\n");
	// str	path = append(binaryPath, command);
	// printf("Path = %s\n", path);
	// str args[] = {"ls", "-la" , NULL};
	// execve(path, args, envp);
	// printf("Done\n");
}