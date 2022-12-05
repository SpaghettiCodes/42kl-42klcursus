#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include <sys/types.h> 
#include <sys/wait.h> 

int    main(int argc, char **argv, char **envp)
{
    int        infilefd;
    int        outfilefd;
    int        pipefd[2];
    int        pid1;
    int        pid2;
    char    *cmd;
    char    **cmd_path;
    
    if (pipe(pipefd) == -1)
        perror("Pipe creation failed");

	infilefd = open("infile", O_RDONLY | O_CREAT, 0777); // open infile and redirect stdin to infile
	outfilefd = open("pizza", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	printf("%d, %d\n", infilefd, outfilefd);

    pid1 = fork();
    if (pid1 < 0)
        perror("Fork 1 failed");
    else if (pid1 == 0) //child process for command 1
    {
        close(pipefd[0]);

        dup2(infilefd, STDIN_FILENO);
        close(infilefd);

        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

		char	*args[] =
		{
			"ls", "-la", 0
		};
		perror("child1 executing\n");
        execve("/usr/bin/ls", args, envp);
    }
	else
	{
		pid2 = fork();
		if (pid2 < 0)
			perror("Fork 2 failed");
		else if (pid2 == 0) //child process for command 2
		{
			close(pipefd[1]);

			dup2(outfilefd, STDOUT_FILENO);
			close(outfilefd);

			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);

			char	*args2[] = 
			{
				"cat", 0
			};

			perror("child2 executing\n");
			execve("/usr/bin/cat", args2, envp);
		}
		else
		{
			close(pipefd[0]);
			close(pipefd[1]);
			waitpid(pid1, NULL, 0);
			waitpid(pid2, NULL, 0);
			printf("Done\n");
		}
	}
}