#include "minishell.h"

int	change_dir(char	**arg, t_cmd_info *shell_info)
{
	int		arg_count;
	char	*oldpwd;
	char	*newpwd;
	t_val	*searcher;

	arg_count = count_arg(arg);
	if (arg_count > 2)
	{
		shell_info->last_exit = eprint("cd", "too many arguments");
		return (0);
	}

	searcher = search_variable("PWD", shell_info->global_var);
	if (!searcher)
		eprint("cd", "PWD is unset, PWD will not be updated");
	oldpwd = getcwd(NULL, 0);

	if (!ft_strcmp(arg[1], "~"))
		newpwd = &search_variable("HOME", shell_info->global_var)->theline[5];
	else if (!ft_strcmp(arg[1], "-"))
		newpwd = &search_variable("OLDPWD", shell_info->global_var)->theline[7];
	else
		newpwd = arg[1];
		
	if (chdir(newpwd) == -1)
	{
		shell_info->last_exit = eprint("cd", "directory does not exist");
		return (0);
	}

	newpwd = getcwd(NULL, 0);	
	printf("changed working dir from %s to %s\n", oldpwd, newpwd);
	if (searcher)
	{
		free_val_content(searcher);
		replace_val(searcher, n_append("PWD=" ,newpwd), 3);
	}
	free(newpwd);

	searcher = search_variable("OLDPWD", shell_info->global_var);
	if (!searcher)
		searcher = add_back_variable(&shell_info->global_var);
	fill_val(searcher, 1, n_append("OLDPWD=", oldpwd), 6);
	searcher->type = ENV;
	free(oldpwd);

	return (0);
}