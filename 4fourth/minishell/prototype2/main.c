#include "minishell.h"
char	*gnl()
{
	char	*ret;

	ret = readline("\033[0;31mminis-hell\033[0;37m: ");
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
	new->tokens = NULL; 
	new->next = NULL;
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
	char *dict = "><|\'\"_\0";
	int	i = 0;

	while (i < SYMBOL_COUNT)
	{
		if (x == dict[i])
			return (i + 1);
		i++;
	}
	return (0);
}

int	search_element(char *input, char to_search, int start)
{
	while (input[start])
	{
		if (input[start] == to_search)
			return (start);
		start++;
	}

	return (-1);
}

bool	skip_space(char *input, int *i)
{
	// skip spaces
	while (input[*i] == SPACE_sym)
		(*i)++;

	if (!input[*i] || input[*i] == '|')
		return (0);

	return (1);
}

t_token	*make_token(char *input, t_token *current, int start, int end)
{
	current->string = ft_substr2(input, start, end);

	current->type = 0;

	if (current->string[0] == '\'' || current->string[0] == '\"')
		current->type = current->type | ((current->string[0] == '\'') * SINGLE) | BUNNY_EAR;

	if (search_element(current->string, '=', 0) != -1 && !(current->type & BUNNY_EAR))
		current->type = current->type | VAR_ASSIGN;
	if (search_element(current->string, '$', 0) != -1 && !(current->type & SINGLE))
		current->type = current->type | VAR_USE;

	printf("Token found %s\n", current->string);
	current->next = init_token(current->token_no + 1);
	return (current->next);
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
				token_current->type = token_current->type | REDIRECT;
				++i;
			}
			else if (input[i] == '\'' || input[i] == '\"')
			{
				initial = i;
				i = search_element(input, input[initial], initial + 1);
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
			else if (input[i] == SPACE_sym)
				token_current = make_token(input, token_current, start, i);
			else if (input[i] == '\0' || input[i] == '|')
			{
				if (start - i)
					make_token(input, token_current, start, (i - 1));
				break;
			}
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

void	redirect_fd(t_token **current, t_cmd *command)
{

}


t_token	*del_token_node(t_token **token, t_token *find)
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

void	process_tokens(t_cmd *command, t_val *global_var, t_val *private_val)
{
	t_token *current;
	int		tkn_found;

	printf("in processing tokens\n");

	tkn_found = 0;
	current = command->tokens;
	printf("start\n");
	while ( current )
	{
		printf("token = %s\n", current->string);
		if (current->type & VAR_USE)
		{
			printf("replacing variables\n");
			replace_variable(current->string, global_var, private_val);
		}

		if ((current->type & VAR_ASSIGN) && !tkn_found)
		{
			printf("assigning var\n");
			if (new_variable(current->string, private_val))
			{
				current = del_token_node(&command->tokens, current);
				continue ;
			}
		}

		if (current->type & REDIRECT)
		{
			printf("redirecting fd\n");
			redirect_fd(&current, command);
		}
		printf("one token done\n");
		++tkn_found;
		current = current->next;
	}
}

void	parse(char *input, t_cmd_info *cmd_info)
{
	t_cmd	*cmd;
	t_cmd	*current;
	int		i;
	int		end;

	end = ft_strlen(input);
	cmd = init_cmd();

	current = cmd;
	i = 0;

	while (i < end)
	{
		++cmd_info->no_cmd;
		current->tokens = extract(input, &i, end);
		if (input[i] == '|')
		{
			current->next = init_cmd();
			current = current->next;
			i++;
		}
	}

	// debug purposes
	current = cmd;
	while (current)
	{
		t_token *current2 = current->tokens;
		while (current2)
		{
			printf("tokens = %s, type = %d\n", current2->string, current2->type);
			current2 = current2->next;
		}
		current = current->next;
	}

	cmd_info->cmd = cmd;
}

void	process(char *input, t_val *global_var, t_val *private_var)
{
	t_cmd_info	cmd_main;
	t_cmd *current;

	cmd_main.no_cmd = 0;
	cmd_main.global_var = global_var;
	cmd_main.private_var = private_var;
	parse(input, &cmd_main);

	current = cmd_main.cmd;

	while (current)
	{
		process_tokens(current, cmd_main.global_var, cmd_main.private_var);
		current = current->next;
	}
}

int	get_input(t_val *global_var, t_val *private_var)
{
	char	*input;

	input = gnl();
	if (!input)
		exit(3);
	else if (*input)
	{
		process(input, global_var, private_var);
		free(input);
	}
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

void print_val(t_val *local_val)
{
	t_val *current;


	printf("current val = \n");
	current = local_val;
	if (current->keyword == NULL)
	{
		printf("empty!\n");
		return ;
	}
	while (current)
	{
		printf("key = %s, define = %s\n", current->keyword, current->define);
		current = current->next;
	}
}

int main(int ac, char *av, char **envp)
{
	t_val	*global_var;
	t_val	*local_var;
	// struct sigaction s_sigaction;

	// // signal actions and stuff

	// s_sigaction.sa_handler = signal_handler;
	// // yep, no idea how sigempty set works at all
	// sigemptyset(&s_sigaction.sa_mask);
	// // ctrl + c
	// sigaction(SIGINT, &s_sigaction, 0);
	// // ctrl + backslash ( not working :( )
	// sigaction(SIGQUIT, &s_sigaction, 0);

	global_var = get_envval(envp);
	local_var = init_val();
	// t_val *current = global_var;
	// while (current)
	// {
	// 	printf("%s = %s\n", current->keyword, current->define);
	// 	current = current->next;
	// }
	printf("amogus\n");
	printf("Terminal Name = %s\n", ttyname(STDIN));
	while (1)
	{
		print_val(local_var);
		get_input(global_var, local_var);
	}
}