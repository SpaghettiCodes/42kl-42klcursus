#include "minishell.h"

// https://stackoverflow.com/questions/42563400/hide-c-pressing-ctrl-c-in-c thanks stack overflow very cool
// https://stackoverflow.com/questions/68602211/forcing-a-terminal-not-to-print-ctrl-hotkeys-when-signals-are-caught

// this does not work on ubuntu (allegedly works on mac)

void	symbol_b_gone()
{
	struct termios attributes;

	// get terminal attribute
	tcgetattr(STDIN_FILENO, &attributes);
	// enable -echoctl
	attributes.c_lflag &= ~ECHOCTL;
	// set terminal attribute
	tcsetattr(STDIN_FILENO, TCSANOW, &attributes);
}

void new_line()
{
	write(1, "\n", 1);
	// write(1, "\033[0;31mminis-hell\033[0;37m:", 26);
	// new line
	rl_on_new_line();
	// clears the input
	rl_replace_line("", 0);
	// displays the empty input
	rl_redisplay();
}
