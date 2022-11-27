#include "pipex.h"

char	*append(char *str1, char *str2)
{
	char	*ret;
	int	i;
	int	j;

	ret = malloc (ft_strlen(str1) + ft_strlen(str2) + 1);
	i = 0;
	while (str1 && str1[i])
	{
		ret[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2 && str2[j])
	{
		ret[i] = str2[j];
		j++;
		i++;
	}
	ret[i] = 0;
	free(str1);
	return (ret);
}

int		find_in_string(char *str1, char *str2)
{
	int	i;
	
	i = 0;
	while (str2[i] && str1[i] && str2[i] != '\n')
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

char	*get_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (find_in_string(envp[i], "PATH\0"))
			return (&envp[i][5]);
		i++;
	}
	return (NULL);
}

char	*get_binarypath(char **envp, char *command, t_pipex fl_desc)
{
	char	*test;
	int		i;
	char	**paths;

	paths = ft_split(get_paths(envp), ':');
	i = -1;
	while (paths[++i])
	{
		paths[i] = append(paths[i], "/\0");
		paths[i] = append(paths[i], command);
		test = paths[i];
		if (access(test, F_OK) == 0)
			return (test);
		free(test);
	}
	return (NULL);
}