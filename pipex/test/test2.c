#include "test.h"

// i am a clown
// 2 pipes is more than enough to have a 2 way pipe communication
// wait then why 1 pipe cant????????

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
// status = 0 - read, 1 - write

char	*append(char *source, char *dest)
{
	char	*ret;
	int		i; 
	int		j;

	ret = (char *) malloc (sizeof(char) * (str_len(source) + str_len(dest) + 1));
	i = -1;
	while (source && source[++i])
		ret[i] = source[i];
	j = 0;
	while (dest && dest[j])
	{
		ret[i] = dest[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	free(dest);
	return (ret);
}

char	*get_input(int fd)
{
	char	*ret;
	char	buffer[100];
	int		check;

	ret = NULL;
	while (1)
	{
		check = read(fd, buffer, 99);
		if (!check)
			break;
		buffer[check + 1] = '\0';
		ret = append(buffer, ret);
	}
	return (ret);
}

char	**my_understanding_is_shit(char *content, char *command_line)
{
	
}

void	run_execve(char *content, char *envp[], char *command_line)
{
	char	**fuckquestionmark;

	fuckquestionmark = my_understanding_is_shit(content, command_line);
}

char	*read_from_pipe(int pipefd, int *status, char *command_line, char *envp[])
{
	int		check;
	char	BUFF[100];
	char	*content;

	while (1)
	{
		check = read(pipefd, BUFF, 99);
		if (check)
		{
			content = NULL;
			while (1)
			{
				BUFF[check + 1] = 0;
				content = append(BUFF, content);
				check = read(pipefd, BUFF, 100);
				if(!check)
					break;
			}
			break;
		}
	}
	run_execve(content, envp, command_line);
	*status = 1;
	return (content);
}

void	write_to_pipe(int pipefd, int *status, char *stuff_to_write)
{
	write(pipefd, stuff_to_write, str_len(stuff_to_write));
	printf("Written To Pipe\n");
	*status = 0;
}

int	child2_process(int *pipefd, int ac, char **av, char *envp[])
{
	char BUFF[100];
	char *content;
	int check;
	int	status;
	int count;

	count = 1;
	status = 0;
	content = 0;
	while (count < ac)
	{
		if (!status)
		{
			content = read_from_pipe(pipefd[2], &status, av[count], envp);
			if (count == (ac - 1))
				write_to_pipe(pipefd[5], &status, content);
		}
		else
		{
			write_to_pipe(pipefd[1], &status, content);
		}
		count++;
	}
}

int	child_process(int *pipefd, int ac, char **av, char *envp[])
{
	char BUFF[100];
	char *content;
	int check;
	int status;
	int count;

	count = 1;
	status = 1;
	content = NULL;
	while (count < ac)
	{
		if (!status)
		{
			content = read_from_pipe(pipefd[0], &status, av[count], envp);
			if (count == (ac - 1))
			{
				write_to_pipe(pipefd[5], &status, content);
			}
		}
		else
		{
			if (count == 1)
			{
				content = get_input(pipefd[4]);
				write(pipefd[3], content, str_len(content));
				free(content);
				status = 0;
			}
			else
				write_to_pipe(pipefd[3], &status, content);
		}
		count++;
	}
}

int main(int ac, char *av[], char *envp[])
{
	int pfd[6]; //0 = read, 1 = write // 4= infile, 5 = outfile
	int	childpid;
	int	child2pid;
	int	infile;
	int	outfile;

	pfd[4] = open(av[1], O_RDONLY);
	pfd[5] = open(av[ac - 1], O_RDWR);
	pipe(pfd);
	pipe(pfd + 2); //2 = read, 3 = write
	childpid = fork();
	if (childpid < 0)
		printf("Failed\n");
	else if (childpid == 0) //child
	{
		child_process(pfd, ac, av, envp);
	}
	else //parent
	{
		child2pid = fork();
		if (child2pid < 0)
			printf("Failed\n");
		if (child2pid == 0)
			child2_process(pfd, ac, av, envp);
	}
	// doesnt work in windows envi
	//  pid_t waitpid(pid_t pid, int *status_ptr, int options);
	// status_ptr = points to location where waitpid can store a value
	// basically - stores what the child process returns
	// will store 0 if it child exit successfully, otherwise, the value can be analyzed with "Status Analysis Macros"
	//waitpid(childpid, null, 0)
	//waitpid(childpid2, null, 0)
	close(pfd[0]);
	close(pfd[1]);
	close(pfd[2]);
	close(pfd[3]);
}