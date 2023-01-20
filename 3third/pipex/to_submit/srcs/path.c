/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:06:22 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/21 00:32:59 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_binarypath(char *command, char **paths)
{
	char	*test;
	int		i;

	i = -1;
	while (paths[++i])
	{
		test = n_append(paths[i], "/\0");
		test = append(test, command);
		if (access(test, X_OK) == 0)
			return (test);
		free(test);
	}
	eprint(command, "command not found");
	return (NULL);
}

void	parse_path(t_pipex *data)
{
	int		i;
	char	**splitted;

	i = -1;
	data->binary_paths = malloc (sizeof(char *) * (data->cmd_num + 1));
	while (++i < data->cmd_num)
	{
		splitted = ft_split(data->cmd[i], ' ');
		if (splitted)
		{
			data->binary_paths[i] = get_binarypath(splitted[0], data->path);
			free_double_arr(splitted);
		}
	}
	data->binary_paths[i] = 0;
}