#include "minishell.h"

// https://stackoverflow.com/questions/42563400/hide-c-pressing-ctrl-c-in-c thanks stack overflow very cool
// https://stackoverflow.com/questions/68602211/forcing-a-terminal-not-to-print-ctrl-hotkeys-when-signals-are-caught

// this does not work on ubuntu (allegedly works on mac)

void	symbol_b_gone()
{
	struct termios	termios_new;

	tcgetattr(STDIN_FILENO, &termios_new);
	termios_new.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &termios_new);
	tcsetattr(0, 0, &termios_new);
}

void new_line()
{
	write(1, "\n", 1);
	// write(1, "\033[0;31mminis-hell\033[0;37m:", 26);
	// clears the input
	rl_replace_line("", 0);
	// new line
	rl_on_new_line();
	// displays the empty input
	rl_redisplay();
}
