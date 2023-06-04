#include "minishell.h"

// count number to token
unsigned int	count_token(t_token *in)
{
	unsigned int	i;
	t_token			*cur;

	i = 0;
	cur = in;
	while (cur)
	{
		cur = cur->next;
		++i;
	}
	return (i);
}

// initialize a double array with NULL (you know, should have used ft_calloc)
char	**init_darray(unsigned int size)
{
	char	**ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char *) * size);
	while (i < size)
	{
		ret[i] = NULL;
		++i;
	}
	return (ret);
}

// trim the symbols in string, WILL FREE STRING
char	*trim_symbols(char	*string)
{
	char	*ret;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(string) - 1;

	if (string[end] == '_')
		--end;
	if ((string[start] == '\'' && string[end] == '\'') || 
			string[start] == '\"' && string[end] == '\"')
	{
		++start;
		--end;
	}
	ret = ft_substr2(string, start, end);
	free(string);
	return (ret);
}

// reconstruct token to a double array (dump into execve)
char	**token_to_darray(t_token *in)
{
	char				**ret;
	char				*temp;
	t_token				*cur;
	unsigned int		size;
	unsigned int		i;

	i = 0;
	size = count_token(in);
	cur = in;
	ret = init_darray(size);
	while (cur && cur->string)
	{
		if (!ret[i])
			ret[i] = trim_symbols(ft_strdup(cur->string));
		else
		{
			temp = trim_symbols(ft_strdup(cur->string));
			ret[i] = append(ret[i], temp);
			free(temp);
		}
		// debug
		printf("%s\n", ret[i]);
		if ((cur->string[ft_strlen(cur->string) - 1] == SPACE_sym) || !cur->next->string)
			++i;
		cur = cur->next;
	}
	ret[i] = 0;
	return (ret);
}

// reconstruct processed token back to a string
char	*token_to_string(t_token *cur)
{
	char	*ret;

	ret = NULL;
	while (cur && cur->string)
	{
		ret = append(ret, cur->string);
		cur = cur->next;
	}
	return (ret);
}

// debug
void	print_darray(char **str)
{
	printf("in string array (final array)\n");
	for (int i = 0; str[i]; ++i)
	{
		printf("%s\n", str[i]);
	}
	printf("NULL\n");
}

char	*gnl()
{
	char	*ret;

	// printf("\033[0;31mminis-hell\033[0;37m:");
	ret = readline("\033[0;31mminis-hell\033[0;37m: ");
	// ret = readline("\033[0;31mminis-hell\033[0;37m: ");
	if (ret && *ret)
		add_history(ret);
	return (ret);
}

t_cmd	*init_cmd()
{
	t_cmd	*new;

	new = malloc (sizeof(t_cmd));
	new->infd = STDIN;
	new->outfd = STDOUT;
	new->final_cmd_line = NULL;
	new->tokens = NULL; 
	new->next = NULL;
	new->redir = 0;
	new->redir_info = NULL;
	return (new);
}

t_token		*init_token(int	token_no)
{
	t_token	*new;

	new = malloc (sizeof(t_token));	
	new->token_no = token_no;
	new->type = 0;
	new->string = NULL;
	new->next = NULL;
	return (new);
}

int	partoftoken(char x)
{
	// remember to replace the space here
	char	*dict = "?><|\'\"_=\0";
	int		i;

	i = 0;
	while (i < SYMBOL_COUNT)
	{
		if (x == dict[i])
			return (i + 1);
		++i;
	}
	return (0);
}

// this just skip spaces and returns if it hits the end_tokens (\0 and '|')
bool	skip_space(char *input, int *i)
{
	// skip spaces
	while (input[*i] == SPACE_sym)
		++(*i);
	if (!input[*i] || input[*i] == '|')
		return (0);
	return (1);
}

t_token	*make_token(char *input, t_token *current, int start, int end)
{
	current->string = ft_substr2(input, start, end);

	current->type = 0;

	if (search_character(current->string, '/', 0, MAX_SIZE) != -1)
		current->type = current->type | FILE_PATH;

	if (current->string[0] == '\'' || current->string[0] == '\"')
		current->type = current->type | ((current->string[0] == '\'') * SINGLE) | BUNNY_EAR;

	if (search_character(current->string, '=', 0, MAX_SIZE) != -1 && !(current->type & BUNNY_EAR))
		current->type = current->type | VAR_ASSIGN;
	if (search_character(current->string, '$', 0, MAX_SIZE) != -1 && !(current->type & SINGLE))
		current->type = current->type | VAR_USE;
	// miiiight wanna reformat this
	if (search_character(current->string, '>', 0, MAX_SIZE) != -1 
		|| search_character(current->string, '<', 0, MAX_SIZE) != -1
		&& !(current->type & BUNNY_EAR))
		current->type = current->type | REDIRECT;

	printf("Token found %s\n", current->string);
	current->next = init_token(current->token_no + 1);
	return (current->next);
}

int	scan_for_var_assign(char *input, t_token *current, int start, int end)
{
	int		equal_loc;
	int		strlen;
	int		found_ears;

	strlen = ft_strlen(input);
	found_ears = 0;
	while (end < strlen)
	{
		++end;
		if (partoftoken(input[end]))
		{
			if ((input[end] == '\"' || input[end] == '\''))
			{
				// TODO = worry about how to remove the fucking bunny ears here
				if (input[end] == input[start])
					found_ears = (found_ears == 0);
				continue;
			}
			if (found_ears)
				continue;
			break;
		}
	}
	make_token(input, current, start, end);
	return (end + 1);
}

t_token	*extract(char *input, int *index, int max_size)
{
	t_token *token;
	t_token *token_current;
	int	i;
	int	start;
	int	initial;

	token = init_token(0);
	token_current = token;
	i = *index;

	// skip leading whitespaces
	skip_space(input, &i);
	start = i;
	while (i <= max_size)
	{
		if (partoftoken(input[i]))
		{
			if (input[i] == '>' || input[i] == '<')
			{
				if ((start - i))
				{
					token_current = make_token(input, token_current, start, i - 1);
					start = i;
				}
				if (input[i] == input[i + 1])
					++i;
				token_current = make_token(input, token_current, start, i);
				++i;
			}
			else if (input[i] == '\'' || input[i] == '\"')
			{
				initial = i;
				i = search_character(input, input[initial], initial + 1, MAX_SIZE);
				if (i == -1)
				{
					i = ++initial;
					continue;
				}
				if ((start - initial))
				{
					token_current = make_token(input, token_current, start, initial - 1);
					start = initial;
				}
				token_current = make_token(input, token_current, start, (i + (input[i + 1] == SPACE_sym)));
				++i;
			}
			else if (input[i] == SPACE_sym || input[i] == '?')
				token_current = make_token(input, token_current, start, i);
			else if (input[i] == '\0' || input[i] == '|')
			{
				if (start - i)
					make_token(input, token_current, start, (i - 1));
				break;
			}
			else if (input[i] == '=')
				i = scan_for_var_assign(input, token_current, start, i + 1);
			// i = i + (input[i] == '?');
			if (!skip_space(input, &i))
				break;
			start = i;
		}
		else
			i++;
	}
	*index = i;
	return (token);
}

t_token	*del_specific_token(t_token **token, t_token *find)
{
	t_token *current;
	t_token *next;
	t_token *prev;

	prev = NULL;
	current = (*token);
	while (current && find->token_no != current->token_no)
	{
		prev = current;
		current = current->next;
	}
	if (!current)
		return prev;
	if (prev)
		prev->next = current->next;
	else
		(*token) = current->next;
	free (current->string);
	free (current);
	if (prev)
		return (prev);
	else
		return ((*token));
}

t_redir	*init_redir(char *file_name)
{
	t_redir *ret;

	ret = malloc(sizeof(t_redir));
	ret->file_name = file_name;
	ret->type = 0;
	return (ret);
}

t_redir	*add_back_redir(t_redir *list, t_redir *new)
{
	while (list->next)
	{
		list = list->next;
	}
	list->next = new;
}

int		determine_type(t_token *current)
{
	if (current->string[0] == '>')
	{
		if (ft_strlen(current->string) == 2)
			return (OUT_APP);
		return (OUT_DEF);
	}
	else if (current->string[0] == '<')
	{
		if (ft_strlen(current->string) == 2)
			return (HEREDOC);
		return (IN_DEF);
	}
	return (0);
}

t_token	*save_redir_info(t_cmd *command, t_token **main, t_token *current)
{
	t_token	*ret;
	t_redir	*new;
	t_token	*next;
	int		type;

	// set ups
	command->redir = 1;
	next = current->next;
	ret = current->next->next;

	// determine the type of redirection
	type = determine_type((current));

	// delete used token
	(*main) = del_specific_token(main, current);

	// determine the file_name // eof string
	new = init_redir(ft_strdup(next->string));
	if (!command->redir_info)
		command->redir_info = new;
	else
		add_back_redir(command->redir_info, new);

	// remove used token
	(*main) = del_specific_token(main, next);

	// return new place to be;
	return (ret);
}

int	find_symbol(char *str, int to_match, int start)
{
	while (str[start])
	{
		if (str[start] == to_match)
			return (start);
		++start;
	}
	return (-1);
}

void	reassign_token_num(t_token *all)
{
	int	i;

	i = 0;
	while (all)
	{
		all->token_no = i;
		++i;
		all = all->next;
	}
}

void	check_space_and_seperate(t_token *current, t_token *all)
{
	t_token	*new;
	char	*storage[2];
	int		start;
	int		end;

	start = 0;
	while (1)
	{
		end = find_symbol(current->string, SPACE_sym , start);
		if (end == -1)
			return;
		storage[0] = ft_substr2(current->string, start, end);
		storage[1] = ft_substr2(current->string, end + 1, ft_strlen(current->string) - 1);
		free(current->string);
		current->string = storage[0];

		new = init_token(-1);
		new->string = storage[1];
		new->next = current->next;
		current->next = new;
		current = current->next;
	}
	reassign_token_num(all);
}

void	process_tokens(t_cmd *command, t_cmd_info *minishell)
{
	t_token *current;
	int		cmd_found;

	printf("in processing tokens\n");
	cmd_found = 0;
	current = command->tokens;
	while ( current )
	{
		if (current->type & VAR_USE)
		{
			printf("replacing variables\n");
			replace_variable(&(current->string), minishell);
			if (!(current->type & BUNNY_EAR))
				check_space_and_seperate(current, command->tokens);
		}
		if ((current->type & VAR_ASSIGN) && !cmd_found)
		{
			printf("assigning var\n");
			if (new_variable(current->string, &minishell->global_var, 1))
			{
				current = del_specific_token(&command->tokens, current);
				continue ;
			}
		}
		printf("one token done\n");
		current = current->next;
	}
	current = command->tokens;
	while (current)
	{
		if (current->type & REDIRECT)
			current = save_redir_info(command, &command->tokens, current);
		current = current->next;
	}
}

int	parse(char *input, t_cmd_info *cmd_info)
{
	t_cmd	*cmd;
	t_cmd	*current;
	int		i;
	int		end;

	end = ft_strlen(input);
	cmd = init_cmd();
	current = cmd;
	i = 0;
	while (1)
	{
		current->tokens = extract(input, &i, end + 1);
	
		process_tokens(current, cmd_info);
	
		current->final_cmd_line = token_to_darray(current->tokens);

		// debug
		print_darray(current->final_cmd_line);

		remove_all_token(&current->tokens);
		printf("Deleted all tokens\n");

		++cmd_info->no_cmd;

		if (input[i] == '\0')
			break;

		if (input[i] == '|')
		{
			if (!input[i+1])
			{
				cmd_info->cmd = cmd;
				free_cmd_info(cmd_info);
				return (eprint("parser", "expected characters after | symbol"));
			}
			current->next = init_cmd();
			current = current->next;
			++i;
		}
	}

	// // this is some serious debuggin
	// current = cmd;
	// while (current)
	// {
	// 	t_token *current2 = current->tokens;
	// 	while (current2)
	// 	{
	// 		printf("tokens = %s, type = %d\n", current2->string, current2->type);
	// 		current2 = current2->next;
	// 	}
	// 	current = current->next;
	// }

	cmd_info->cmd = cmd;
	return (0);
}

void	process(char *input, t_cmd_info *cmd_main)
{
	t_cmd		*current;

	cmd_main->no_cmd = 0;
	if ( parse(input, cmd_main) )
		return ;
	printf("executing\n");
	execute(cmd_main);
	free_cmd_info(cmd_main);
}

int	get_input(t_cmd_info *cmd_main)
{
	char	*input;

	input = gnl();
	if (!input)
		return (3);
	else if (*input)
	{
		process(input, cmd_main);
		free(input);
	}
	return (0);
}

void print_val(t_val *variables)
{
	t_val	*current;


	printf("current val = \n");
	current = variables;
	if (!current->theline)
	{
		printf("empty!\n");
		return ;
	}
	while (current)
	{
		printf("full length = %s, define = %s\n", current->theline, &current->theline[current->equalloc + 1]);
		current = current->next;
	}
}

// void	shell_signal()
// {
// 	struct	sigaction sig_nl;
// 	struct	sigaction sig_ign;

// 	// fuck sigaction
// 	// signal actions and stuff
// 	sig_nl.sa_handler = new_line;
// 	sig_ign.sa_handler = SIG_IGN;
// 	sig_nl.sa_flags = 0;
// 	sig_ign.sa_flags = 0;
// 	sigemptyset(&sig_nl.sa_mask);
// 	sigemptyset(&sig_ign.sa_mask);
// 	// ctrl + c
// 	sigaction(SIGINT, &sig_nl, 0);
// 	// ctrl + backslash
// 	sigaction(SIGQUIT, &sig_ign, 0);
// }

void update_env(t_val *global_var)
{
	t_val	*search;
	char	*val;

	// no need to free search since this 2 just poinst to envp
	search = search_variable("SHLVL", global_var);
	val = &search->theline[search->equalloc + 1];
	val = ft_itoa(ft_atoi(val) + 1);
	fill_val(search, 1, n_append("SHLVL=", val), search->equalloc);
	search->type = ENV;
	free(val);

	search = search_variable("SHELL", global_var);
	val = getcwd(NULL, 0);
	val = append(val, EXE_NAME);
	fill_val(search, 1, n_append("SHELL=", val), search->equalloc);
	search->type = ENV;
	free(val);
}

struct termios	saved;

int main(int ac, char *av, char **envp)
{
	t_cmd_info	minishell;

	struct termios	termios_new;

	// get terminal attribute (man stty) (init the saved attribute)
	tcgetattr(STDIN_FILENO, &saved);
	// // at exit, restore all terminal attribute to default
	// atexit(restore);

	tcgetattr(STDIN_FILENO, &termios_new);
	termios_new.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &termios_new);
	tcsetattr(0, 0, &termios_new);

	// just to remove the ^C and ^\ 
	// symbol_b_gone();
	minishell.last_exit = 42069;
	minishell.global_var = get_envval(envp);
	update_env(minishell.global_var);
	// print_val(global_var);

	printf("amogus\n");
	printf("Terminal Name = %s\n", ttyname(STDIN));
	while (1)
	{
		signal(SIGINT, new_line);
		signal(SIGQUIT, SIG_IGN);
		// symbol_b_gone();
		if (get_input(&minishell))
			break ;
	}
	delete_all_var(&minishell.global_var);
	rl_clear_history();
	clean_exit(NULL);
}