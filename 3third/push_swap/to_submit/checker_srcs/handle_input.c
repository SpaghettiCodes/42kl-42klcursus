/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:04:54 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 17:26:53 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (1);
}

/*               No switches?
** ⠀⣞⢽⢪⢣⢣⢣⢫⡺⡵⣝⡮⣗⢷⢽⢽⢽⣮⡷⡽⣜⣜⢮⢺⣜⢷⢽⢝⡽⣝
** ⠸⡸⠜⠕⠕⠁⢁⢇⢏⢽⢺⣪⡳⡝⣎⣏⢯⢞⡿⣟⣷⣳⢯⡷⣽⢽⢯⣳⣫⠇
** ⠀⠀⢀⢀⢄⢬⢪⡪⡎⣆⡈⠚⠜⠕⠇⠗⠝⢕⢯⢫⣞⣯⣿⣻⡽⣏⢗⣗⠏⠀
** ⠀⠪⡪⡪⣪⢪⢺⢸⢢⢓⢆⢤⢀⠀⠀⠀⠀⠈⢊⢞⡾⣿⡯⣏⢮⠷⠁⠀⠀
** ⠀⠀⠀⠈⠊⠆⡃⠕⢕⢇⢇⢇⢇⢇⢏⢎⢎⢆⢄⠀⢑⣽⣿⢝⠲⠉⠀⠀⠀⠀
** ⠀⠀⠀⠀⠀⡿⠂⠠⠀⡇⢇⠕⢈⣀⠀⠁⠡⠣⡣⡫⣂⣿⠯⢪⠰⠂⠀⠀⠀⠀
** ⠀⠀⠀⠀⡦⡙⡂⢀⢤⢣⠣⡈⣾⡃⠠⠄⠀⡄⢱⣌⣶⢏⢊⠂⠀⠀⠀⠀⠀⠀
** ⠀⠀⠀⠀⢝⡲⣜⡮⡏⢎⢌⢂⠙⠢⠐⢀⢘⢵⣽⣿⡿⠁⠁⠀⠀⠀⠀⠀⠀⠀
** ⠀⠀⠀⠀⠨⣺⡺⡕⡕⡱⡑⡆⡕⡅⡕⡜⡼⢽⡻⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
** ⠀⠀⠀⠀⣼⣳⣫⣾⣵⣗⡵⡱⡡⢣⢑⢕⢜⢕⡝⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
** ⠀⠀⠀⣴⣿⣾⣿⣿⣿⡿⡽⡑⢌⠪⡢⡣⣣⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
** ⠀⠀⠀⡟⡾⣿⢿⢿⢵⣽⣾⣼⣘⢸⢸⣞⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
** ⠀⠀⠀⠀⠁⠇⠡⠩⡫⢿⣝⡻⡮⣒⢽⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
*/
int	do_stuff(char *input, t_pushswap *stacks)
{
	if (str_cmp(input, "sa\n"))
		return (instructions(0, stacks));
	else if (str_cmp(input, "sb\n"))
		return (instructions(1, stacks));
	else if (str_cmp(input, "ss\n"))
		return (instructions(2, stacks));
	else if (str_cmp(input, "pa\n"))
		return (instructions(3, stacks));
	else if (str_cmp(input, "pb\n"))
		return (instructions(4, stacks));
	else if (str_cmp(input, "ra\n"))
		return (instructions(5, stacks));
	else if (str_cmp(input, "rb\n"))
		return (instructions(6, stacks));
	else if (str_cmp(input, "rr\n"))
		return (instructions(7, stacks));
	else if (str_cmp(input, "rra\n"))
		return (instructions(8, stacks));
	else if (str_cmp(input, "rrb\n"))
		return (instructions(9, stacks));
	else if (str_cmp(input, "rrr\n"))
		return (instructions(10, stacks));
	else
		return (0);
}

int	listeninstruction(t_pushswap *stacks)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0, 0);
		if (!line)
			break ;
		if (!do_stuff(line, stacks))
		{
			free(line);
			get_next_line(0, 1);
			return (errorexit(stacks, NULL, NULL));
		}
		free(line);
	}
	return (1);
}
