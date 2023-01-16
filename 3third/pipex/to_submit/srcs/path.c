#include "pipex.h"

// gets the executable binary file path and returns a malloced string of said pathway
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
	return (NULL);
}