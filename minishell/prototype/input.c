#include "minishell.h"
extern char **environ;

bool	is_alphanum(char ref)
{
	if ((ref <= '9' && ref >= '0') || (ref <= 'z' && ref >= 'a') || (ref >= 'Z' && ref <= 'A'))
		return (TRUE); 
}

int	eprint(char *element, char *msg)
{
	write(2, "The Mouse Behind This Abomination Said: ", 41);
	write(2, "(", 1);
	if (element)
		write(2, element, ft_strlen(element));
	write(2, ")", 1);
	write(2, " ", 1);
	if (msg)
		write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return(11 + ft_strlen(element) + ft_strlen(msg));
}

// compares str1 and str2
int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[i] == str2[i])
	{
		if (!str2[i + 1] && !str1[i + 1])
			return (1);
		i++;
	}
	return (0);
}

// compares str1 and str2, stops comparing str1 at newline
int	ft_strcmp_nl(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[i] == str2[i])
	{
		if (str1[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// appends str2 at the back of str1 -- frees str1 and null terminate the appeneded string
char	*append(char *str1, char *str2)
{
	char	*ret;
	int		i;
	int		j;

	ret = malloc (ft_strlen(str1) + ft_strlen(str2) + 1);
	i = -1;
	while (str1[++i])
		ret[i] = str1[i];
	j = 0;
	while (str2[j])
	{
		ret[i] = str2[j];
		j++;
		i++;
	}
	ret[i] = 0;
	free(str1);
	return (ret);
}

// similar with append BUT does not free str1 and returns a malloced string
char	*n_append(char *str1, char *str2)
{
	char	*ret;
	int		i;
	int		j;

	ret = malloc (ft_strlen(str1) + ft_strlen(str2) + 1);
	i = -1;
	while (str1[++i])
		ret[i] = str1[i];
	j = 0;
	while (str2[j])
	{
		ret[i] = str2[j];
		j++;
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	*gnl()
{
	char	*ret;

	ret = readline("\033[0;31ms-hell\033[0;37m: ");
	if (ret && *ret)
		add_history(ret);
	return (ret);
}

void	free_all(str *item)
{
	int	i;

	i = 0;

	if (item)
		while (item[i])
			i++;
}

char	*get_binarypath(char *command)
{
	char	*test;
	char	**paths;
	int		i;

	i = -1;
	paths = ft_split(getenv("PATH"), ':');
	while (paths[++i])
	{
		test = n_append(paths[i], "/\0");
		test = append(test, command);
		if (access(test, X_OK) == 0)
			return (test);
		free(test);
	}
	free_all(paths);
	return (NULL);
}

bool	has_slash(str cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	find_in(str	str1, char	ref)
{
	int	i;

	i = 0;
	while (str1[i])
	{
		if (str1[i] == ref)
			return (i);
		i++;
	}
	return (-1);
}

char	*sub_str(char	*str, int	start, int	end)
{
	char	*ret;
	int	i;

	ret = malloc (sizeof(char) * ((end - start + 1) + 1));
	i = 0;
	while (start <= end && str[start])
	{
		ret[i] = str[start];
		i++;
		start++;
	}
	ret[i] = 0;
	return (ret);
}

t_variables	*search_lclvar(t_variables	*local_var, str keyword)
{
	t_variables	*current;

	current = local_var;

	while (current->keyword)
	{
		if (ft_strcmp(keyword, current->keyword))
			break;
		current = current->next;
	}

	return (current);
}

t_variables	*init_local()
{
	t_variables	*ret;

	ret = malloc (sizeof(t_variables));
	ret->keyword = NULL; 
	ret->definition = NULL;
	ret->next = NULL;
	return (ret);
}

int 	add_local_val(str cmd, t_variables *local_var)
{
	int		i;
	str	keyword;
	t_variables *current;

	i = find_in(cmd, '=');
	keyword = sub_str(cmd, 0, (i - 1));

	current = search_lclvar(local_var, keyword);

	if (current->keyword)
		free(current->keyword);
	if (current->definition)
		free(current->definition);

	current->keyword = ft_strdup(keyword);
	current->definition = sub_str(cmd, (i + 1), (ft_strlen(cmd) - 1));

	// will change this
	if (!current->next)
		current->next = init_local();
	
	free(cmd);
	cmd = ft_strdup("");
	printf("Added Variable %s with Definition %s\n", current->keyword, current->definition);
	return (0);
}

int	get_darray_length(str *stuff)
{
	int	i;

	i = 0;
	while (stuff[i])
		i++;
	return (i);
}

int	find_last_alphanum(str	string)
{
	int ret;

	ret = 0;
	while (is_alphanum(string[ret]))
		ret++;
	return(ret);
}

char	*getkeyword(str	cmdline)
{
	int		start;
	int		end;
	char	*ret;

	start = 0;
	end = find_last_alphanum((cmdline));
	ret = malloc (end + 1);

	while (start < end && cmdline[start])
	{
		ret[start] = cmdline[start];
		start++;
	}
	ret[start] = 0;
	return (ret);
}

// check if str2 exist in str1
int	strinstr(str str1, str str2)
{
	int	i;
	int	first_occur;
	int	j;

	i = 0;
	while (str1[i])
	{
		j = 0;
		first_occur = i;
		while (str2[j] == str1[i + j])
		{
			if (!str2[j + 1])
				return (first_occur);
			j++;
		}
		i++;
	}

	return (-1);
}

int		get_total_length(str *d_array)
{
	int	ret;
	int	i;
	int	j;

	j = 0;
	ret = 0;
	while (d_array[j])
	{
		i = 0;
		while (d_array[j][i])
		{
			ret++;
			i++;
		}
		j++;
	}
	return (ret);
}

str		combine_array(str *hm)
{
	str	ret;
	int	i;
	int	j;
	int	k;


	ret = malloc (get_total_length(hm) + 1);
	j = 0;
	k = 0;
	while (hm[j])
	{
		i = 0;
		while (hm[j][i])
		{
			ret[k] = hm[j][i];
			k++;
			i++;
		}
		j++;
	}
	ret[k] = 0;
	return (ret);
}

void	replace_and_realloc(str line, t_variables *local_var)
{
	char	*ret;
	int		i;
	t_variables	*current;

	// total_len = ((ft_strlen(cmdline) - (ft_strlen(keyword) + 1)) + ft_strlen(current->definition)) + 1;
	// keywordloc = strinstr(cmdline, keyword);
	// ret = malloc (total_len);

	i = 0;
	current = search_lclvar(local_var, line);
	free(line);
	if (!current->definition)
		line = ft_strdup("");
	else
		line = ft_strdup(current->definition);
}

int	replace_dollar(str cmdline, t_variables *local_var)
{
	int			i;
	str	*hm;

	i = 0;
	hm = ft_split(cmdline, '$');
	while (hm[i])
	{
		replace_and_realloc(hm[i], local_var);
		i++;
	}
	free(cmdline); 
	cmdline = combine_array(hm);
}

int	process_splitted(str *splitted, t_variables	*local_var)
{
	int	i;
	t_variables	*current;

	i = 0;
	while (splitted[i])
	{
		if (find_in(splitted[i], '$') != -1)
		{
			replace_dollar(splitted[i], local_var);
		}
		if (find_in(splitted[i], '=') != -1)
		{
			add_local_val(splitted[i], local_var);
		}
		i++;
	}
	return (0);
}

int	init_cmd(t_info *cmd_info, str cmd, t_variables *local_var)
{
	cmd_info->in_fd = STDIN;
	cmd_info->out_fd = STDOUT;
	cmd_info->full_input = cmd;

	cmd_info->path_defined = has_slash(cmd);

	// splits input (will change in future)
	cmd_info->splitted_input = ft_split(cmd, ' ');
	
	process_splitted(cmd_info->splitted_input, local_var);

	// execve
	cmd_info->command = cmd_info->splitted_input[0];
	cmd_info->arguments = &cmd_info->splitted_input[0];

	if (cmd_info->path_defined)
	{
		cmd_info->command_path = cmd_info->command;
		if (access(cmd_info->command_path, X_OK))
		{
			if (access(cmd_info->command_path, F_OK))
				eprint(cmd_info->command_path, "\"I can't find that file or directory, Squeak!\"");
			else
				eprint(cmd_info->command_path, "\"I can't hack into this file, Squeak!\"");
			return (0);
		}
	}
	else
	{
		// iiiiiiii dont think im suppose to do this
		// well i meant they DID say search and launch the right executable
		cmd_info->command_path = get_binarypath(cmd_info->command);
	}
	if (!cmd_info->command_path)
	{
		eprint(cmd_info->command, "\"I can't find that command, Squeak!\"");
		return (0);
	}
	return (1);
}

int	execute(t_info cmd_info)
{
	dup2(cmd_info.in_fd, STDIN);
	dup2(cmd_info.out_fd, STDOUT);

	if (execve(cmd_info.command_path, cmd_info.arguments, environ) == -1)
		perror(strerror(errno));
}

void	parse(char *cmd, t_variables *local_var)
{
	t_info	cmd_info;
	int	childpid;
	int	ret_val;

	ret_val = init_cmd(&cmd_info, cmd, local_var);

	if(!ret_val)
		return;

	if (cmd_info.command[0])
	{
		childpid = fork();
		if (!childpid)
			execute(cmd_info);
	}

	waitpid(childpid, NULL, 0);
	if (cmd_info.path_defined)
		free(cmd_info.command_path);
	free_all(cmd_info.splitted_input);
}

int	get_input(t_variables	*local_var)
{
	char	*input;

	input = gnl();
	if (input && *input)
	{
		parse(input, local_var);
		free(input);
	}
	else if (!input)
		exit(3);
}
void new_line()
{
	// new line
	printf("\n");

	rl_on_new_line();
	// clears the input
	rl_replace_line("", 0);
	// displays the empty input
	rl_redisplay();
}

void	terminate()
{
	rl_on_new_line();
	rl_redisplay();
}

void	signal_handler(int	signo)
{
	if (signo == SIGINT)
		new_line();
	else if (signo == SIGQUIT)
		terminate();
}

int main()
{
	struct sigaction s_sigaction;
	t_variables *local_var;

	// signal actions and stuff

	local_var = init_local();
	s_sigaction.sa_handler = signal_handler;
	// yep, no idea how sigempty set works at all
	sigemptyset(&s_sigaction.sa_mask);
	// ctrl + c
	sigaction(SIGINT, &s_sigaction, 0);
	// ctrl + backslash
	sigaction(SIGQUIT, &s_sigaction, 0);

	printf("Made by a random dude\nDid the Absolute bare minimum at 3/12/2022\nDid Local Variables at 4/12/2022\nA deranged programmer presents:\nDO NOT, I REPEAT, DO NOT LAUNCH THIS HELL WIHTIN THIS HELL\nGOD THE SIGQUIT STILL DOESNT WORK BRO\n");
	printf("Terminal Name = %s\n", ttyname(STDIN));
	while (1)
	{
		get_input(local_var);
	}
}