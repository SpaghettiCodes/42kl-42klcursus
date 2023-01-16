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
	new->string = NULL;
	new->next = NULL;
}

int	partoftoken(char x)
{
	char *dict = "|\'\"_\0";
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
	while (input[*i] == '_')
		(*i)++;

	if (!input[*i] | input[*i] == '|')
		return (0);

	return (1);
}

int	make_token(char *input, t_token *current, int start, int i)
{
	current->string = ft_substr2(input, start, i);
	if (!current->token_no)
		current->type = CMD;
	else
		current->type = ARG;
	printf("Token found %s\n", current->string);

	current->next = init_token(current->token_no);
	// current = current->next;
	return (i);
}

t_token	*extract(char *input, t_cmd	*current, int *index, int max_size)
{
	t_token *token;
	t_token *token_current;
	int	i;
	int	start;
	int	token_no;
	int	initial;

	token = init_token(0);
	token_current = token;
	i = *index;

	// skip leading whitespaces
	while (input[i] && input[i] == '_')
		i++;

	start = i;
	token_no = 0;
	while (i <= max_size)
	{
		if (partoftoken(input[i]))
		{
			// exact duplicate of "
			// future me please fix

			if (input[i] == '\'')
			{
				// extract any characters before the first "
				if ((start - i))
				{
					make_token(input, token_current, start, i - 1);
					// token_current->string = ft_substr2(input, start, i - 1);
					// if (!token_no++)
					// 	token_current->type = CMD;
					// else
					// 	token_current->type = ARG;

					// printf("pre single ear token found %s\n", token_current->string);

					// token_current->next = init_token();
					token_current = token_current->next;
					start = i;
				}
	
				// search for the second "
				initial = i;
				i = search_element(input, '\'', initial + 1);
				if (i == -1)
				{
					i = ++initial;
					continue;
				}

				// extract content in "" and skips the second "

				make_token(input, token_current, start, i++);
				// token_current->string = ft_substr2(input, start, i++);
				// if (!token_no++)
				// 	token_current->type = CMD;
				// else
				// 	token_current->type = ARG;
				token_current->type = token_current->type | (SINGLE | BUNNY_EAR);
				// printf("single bunny ear token found %s\n", token_current->string);

				// skip spaces
				if (!skip_space(input, &i))
					break;

				// token_current->next = init_token();
				token_current = token_current->next;
				start = i;
			}

			else if (input[i] == '\"')
			{
				// extract any characters before the first "
				if ((start - i))
				{
					make_token(input, token_current, start, i - 1);
					// token_current->string = ft_substr2(input, start, i - 1);
					// if (!token_no++)
					// 	token_current->type = CMD;
					// else
					// 	token_current->type = ARG;
					// printf("pre bunny ear token found %s\n", token_current->string);

					// token_current->next = init_token();
					token_current = token_current->next;
					start = i;
				}
	
				// search for the second "
				initial = i;
				i = search_element(input, '\"', initial + 1);
				if (i == -1)
				{
					i = ++initial;
					continue;
				}

				// extract content in "" and skips the second "
				make_token(input, token_current, start, i++);
				// token_current->string = ft_substr2(input, start, i++);
				// if (!token_no++)
				// 	token_current->type = CMD;
				// else
				// 	token_current->type = ARG;
				token_current->type = token_current->type | BUNNY_EAR;
				printf("bunny ear token found %s\n", token_current->string);

				// skip spaces
				if (!skip_space(input, &i))
					break;

				// token_current->next = init_token(token_current);
				token_current = token_current->next;
				start = i;
			}

			else if (input[i] == '_')
			{
				make_token(input, token_current, start, i);
				// token_current->string = ft_substr2(input, start, i);
				
				// if (!token_no++)
				// 	token_current->type = CMD;
				// else
				// 	token_current->type = ARG;
				// printf("space token found %s\n", token_current->string);

				// skip spaces
				if (!skip_space(input, &i))
					break;

				// token_current->next = init_token();
				token_current = token_current->next;
				start = i;
			}

			else if (input[i] == '\0')
			{
				make_token(input, token_current, start, (i - 1));
				// token_current->string = ft_substr2(input, start, (i - 1));
				// printf("eof token found %s\n", token_current->string);

				// if (!token_no)
				// 	token_current->type = CMD;
				// else
				// 	token_current->type = ARG;

				break;
			}

			// also duplicate of null character (pls fix thanks)
			else if (input[i] == '|')
			{
				make_token(input, token_current, start, (i - 1));
				// token_current->string = ft_substr2(input, start, (i - 1));
				// printf("pipe token found %s\n", token_current->string);

				// if (!token_no)
				// 	token_current->type = CMD;
				// else
				// 	token_current->type = ARG;

				break;
			}
		}
		else
			i++;
	}

	*index = i;
	return (token);
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
		current->tokens = extract(input, current, &i, end);
		if (input[i] == '|')
		{
			current->next = init_cmd();
			current = current->next;
			i++;
		}
	}

	t_token *current2 = cmd->tokens;
	while (current2)
	{
		printf("tokens = %s, type = %d\n", current2->string, current2->type);
		current2 = current2->next;
	}
}

void	process(char *input)
{
	t_cmd_info	cmd;

	parse(input, &cmd);
}

int	get_input()
{
	char	*input;

	input = gnl();
	if (!input)
		exit(3);
	else if (*input)
	{
		process(input);
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

int main(int ac, char *av, char **envp)
{
	// struct sigaction s_sigaction;

	// // signal actions and stuff

	// s_sigaction.sa_handler = signal_handler;
	// // yep, no idea how sigempty set works at all
	// sigemptyset(&s_sigaction.sa_mask);
	// // ctrl + c
	// sigaction(SIGINT, &s_sigaction, 0);
	// // ctrl + backslash ( not working :( )
	// sigaction(SIGQUIT, &s_sigaction, 0);

	printf("amogus\n");
	printf("Terminal Name = %s\n", ttyname(STDIN));
	while (1)
	{
		get_input();
	}
}