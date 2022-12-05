#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <stdlib.h>

#define CTRLC 2
#define CTRLD 3 

void red()
{
	printf("\033[0;31m");
}

void white()
{
	printf("\033[0;37m");
}

void new_line()
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

char	*gnl()
{
	char	*ret;

	ret = readline("\033[0;31ms-hell: \033[0;37m");
	if (ret && *ret)
	{
		add_history(ret);
	}
	return (ret);
}

int main()
{
	signal(CTRLC, new_line);
	// signal(CTRLD, quit_app);
	char	*test;
	while (1)
	{
		test = gnl();
		if (test && *test)
		{
			printf("READ = %s\n", test);
			free(test);
		}
		else if (!test)
			exit(3);
	}
}