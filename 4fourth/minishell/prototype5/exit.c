#include "minishell.h"

extern struct termios	saved;

int	clean_exit(t_cmd_info *to_free_2)
{
	printf("very clean lmao\n");
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &saved);
	exit(0);
}