#include "checker.h"

int	instructions(int input, t_pushswap *stacks)
{
	void	(*action[11])(t_pushswap *stacks);

	action[0] = sa;
	action[1] = sb;
	action[2] = ss;
	action[3] = pa;
	action[4] = pb;
	action[5] = ra;
	action[6] = rb;
	action[7] = rr;
	action[8] = rra;
	action[9] = rrb;
	action[10] = rrr;
	(*action[input])(stacks);
	return(1);
}

int	do_stuff(char *input, t_pushswap *stacks)
{
	if (str_cmp(input, "sa\n"))
		return(instructions(0, stacks));
	if (str_cmp(input, "sb\n"))
		return(instructions(1, stacks));
	if (str_cmp(input, "ss\n"))
		return(instructions(2, stacks));
	if (str_cmp(input, "pa\n"))
		return(instructions(3, stacks));
	if (str_cmp(input, "pb\n"))
		return(instructions(4, stacks));
	if (str_cmp(input, "ra\n"))
		return(instructions(5, stacks));
	if (str_cmp(input, "rb\n"))
		return(instructions(6, stacks));
	if (str_cmp(input, "rr\n"))
		return(instructions(7, stacks));
	if (str_cmp(input, "rra\n"))
		return(instructions(8, stacks));
	if (str_cmp(input, "rrb\n"))
		return(instructions(9, stacks));
	if (str_cmp(input, "rrr\n"))
		return(instructions(10, stacks));
	return (0);
}

int	listeninstruction(t_pushswap *stacks)
{
	char	*line;

	while(1)
	{
		line = get_next_line(0);
		if (!line)
			break;
		if(!do_stuff(line, stacks))
		{
			free(line);
			return(errorexit(stacks));
		}
		free(line);
	}
}