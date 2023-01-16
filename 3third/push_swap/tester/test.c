#include "test.h"

int	ft_zero(char *arr, int num)
{	
	for (int i = 0; i < num; i++)
		arr[i] = 0;
}

int	count_digit(int x)
{
	int	count_digit;
	int ret;

	ret = 1;
	while (x >= 10)
	{
		x /= 10;
		ret++;
	}
	return (ret);
}

char	*itoa(int x)
{
	int digit_count = count_digit(x);
	char *ret = malloc(sizeof(char) * (digit_count + 1));
	
	ret[digit_count--] = 0;
	for (; digit_count >= 0; digit_count--)
	{
		ret[digit_count] = '0' + (x % 10);
		x /= 10;
	}
	return (ret);
}

int	count_lines(int read_end, int write_end, char **envp, int count)
{
	dup2(read_end, STDIN_FILENO);
	close(read_end);

	dup2(write_end, STDOUT_FILENO);
	close(write_end);

	char *args[] = 
	{
		"wc",
		"-l",
		0
	};

	printf("---Test %d---\n", count);
	if (execve("/usr/bin/wc", args, envp) == -1)
		perror(strerror(errno));
}

void	execute(int	write_file, int write_pipe, int len, int count, char **args, char **envp)
{
	dup2(write_file, STDOUT_FILENO);
	close(write_file);
	printf("--- Test %d Numbers ---\n", count);
	for (int i = 1; i < (len + 1); i++)
		printf("%s ", args[i]);
	printf("\n\n");

	dup2(write_pipe, STDOUT_FILENO);
	close(write_pipe);
	if(execve("./your_ps/pushswap", args, envp) == -1)
		printf("Something went wrong LMAO\n");
}

char	**gen_num(int seed, int len)
{
	char check[len];
	char **args;
	int	numbers[len], pfd[2];
	int	num;

	srand(seed);
	ft_zero(check, len);
	for (int i = 0; i < len; i++)
	{
		num = rand() % len;
		if (!check[num])
		{
			check[num] = 1;
			numbers[i] = num;
		}
		else
			i--;
	}
	args = malloc (sizeof(char *) * (len + 2));
	args[0] = strdup("./pushswap");
	for (int i = 1; i < (len + 1); i++)
		args[i] = itoa(numbers[i - 1]);
	args[len + 1] = 0;

	return (args);
}

int	runtest(int test_numfd, int step_takenfd, int count, char **args, char **envp, int seed, int len)
{
	int pfd[2];
	int	childpid;

	//1 is writing 0 is reading
	if (pipe(pfd) == -1)
		return (printf("Piped failed, for some reason\n"));	
	childpid = fork();
	if (!childpid)
	{
		close(pfd[0]);
		close(step_takenfd);
		execute(test_numfd, pfd[1], len, count, args, envp);
	}
	else
	{
		close(test_numfd);
		close(pfd[1]);
		count_lines(pfd[0], step_takenfd, envp, count);
		exit(10);
	}
}

int	average(int	*tab, int size)
{
	unsigned int	ret;

	ret = 0;
	for(int i = 0; i < size; i++)
		ret += (unsigned int) tab[i];
	return (ret / size);
}

int	max(int *sorted_tab, int size)
{
	return (sorted_tab[size - 1]);
}

int	min(int *sorted_tab, int size)
{
	return (sorted_tab[0]);
}

int	find(int *tab, int size, int ref)
{
	int	ret;
	
	for (int ret = 0; ret < size; ret++)
		if (tab[ret] == ref)
			return (ret);
	return (-1);
}

int	stats(int cases, int cases_len)
{
	char	*line;
	int		result[cases], sorted_result[cases], count, statfd, resultfd;

	resultfd = open("./data/step_taken.log", O_RDONLY);
	statfd = open("./data/stats.log", O_WRONLY | O_TRUNC | O_CREAT, 0777);

	count = 0;
	while (1)
	{
		line = get_next_line(resultfd);
		if (!line)
			break;
		if (count % 2)
		{
			result[(count / 2)] = atoi(line);
			sorted_result[(count / 2)] = result[(count / 2)];
		}
		free(line);
		count++;
	}
	q_sort(sorted_result, 0, cases);

	dup2(statfd, STDOUT_FILENO);
	printf("---------- STATS ----------\n");
	printf("NUMBER LENGTH = %d\n", cases_len);
	printf("CASES = %d\n", cases);
	printf("AVERAGE STEPS = %d\n", average(result, cases));
	int max_val = max(sorted_result, cases);
	printf("LARGEST MOVES = %d\n", max_val);
	printf("WORST CASE = %d\n", find(result, cases, max_val) + 1);
	int min_val = min(sorted_result, cases);
	printf("SMALLEST MOVES = %d\n", min_val);
	printf("BEST CASE = %d\n", find(result, cases, min_val) + 1);
	exit(10);
}

void	free_all(char ***args, int gen_count)
{
	for (int i = 0; args[i]; i++)
	{
		for (int j = 0; args[i][j]; j++)
			free(args[i][j]);
		free(args[i]);
	}
	free(args);
}

int setup(int ac, char **av)
{
	if (ac < 3)
		return (printf("Include test count and/or array length!\nExecute the program with the following arguments -\n ./test [number of test cases] [length of numbers]\n"));
	
	if (access("./your_ps/", F_OK))
		return (printf("folder is gone\nwhere is folder\n"));

	system("cd ./your_ps && make re && make clean");

	if (access("./your_ps/pushswap", X_OK))
		return(printf("Brother did you forget your makefile or something?\nMake sure to name the program pushswap\n"));
	printf("Push Swap program found\n");
	return (0);
}

int main(int ac, char **av, char **envp)
{
	int	test_num, step_taken, count, childpid;
	unsigned int seed = time(NULL);
	char	***args;

	// pre.. stuff
	printf("Epic Tester made by a Lazy Fuck (cshi-xia)\n");
	printf("umm is there copyright thing?\n");
	printf("IMPORTANT: THIS TESTER WILL NOT CHECK IF YOUR STEPS WILL SOLVE THE PROGRAM\n");
	printf("ALSO, TESTER SLOW, WAIT PLS (wdy expect its written by me)\n");
	printf("im too lazy to program that in lmao\n\n");

	// error check
	if (setup(ac, av))
		return (10);
	int	gen_count = atoi(av[1]);
	int	arr_len = atoi(av[2]);

	// opening files
	test_num = open("./data/test_nums.log", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	step_taken = open("./data/step_taken.log", O_WRONLY | O_TRUNC | O_CREAT, 0777);

	// generate numbers
	printf("Generating Numbers...\n");
	args = malloc(sizeof(char **) * (gen_count + 1));
	int	i;
	for (i = 0; i < gen_count; i++)
	{
		args[i] = gen_num(seed, arr_len);
		fflush(0);
		printf("Generated %d/%d numbers\r", i + 1, gen_count);
		fflush(0);
		seed += rand() - rand();
	}
	args[i] = 0;

	// running dudes program
	count = 1;
	printf("\nPlease wait...\n");
	printf("In the meantime, go get something to eat\n");
	while (count <= gen_count)
	{
		childpid = fork();
		if (!childpid)
			runtest(test_num, step_taken, count, args[count - 1], envp, seed, arr_len);
		else
		{
			waitpid(childpid, NULL, 0);
			fflush(0);
			printf("Ran %d/%d test cases\r", count, gen_count);
			fflush(0);
			count++;
		}
	}
	printf("\nDone! %d test cases was generated\n", --count);
	close(test_num);
	free_all(args, gen_count);

	// pre-stats
	printf("Everything is in the data folder\n");
	printf("Numbers used in testing is in test_num.log\n");
	printf("Number of step Taken is recorded in step_taken.log\n");
	printf("Seed is based on the time, so wait a while before running this program again\n\n");	

	// generate stats
	childpid = fork();
	if (!childpid)
		stats(gen_count, arr_len);
	else
	{
		int i = 0;
		while (!waitpid(childpid, NULL, WNOHANG))
		{
			if (!(i % 3))
			{
				fflush(0);
				printf("                    \r");
				printf("Generating Stats.\r");
				fflush(0);
			}
			else if (i % 3 == 1)
			{
				fflush(0);
				printf("                   \r");
				printf("Generating Stats..\r");
				fflush(0);
			}
			else
			{
				fflush(0);
				printf("                    \r");
				printf("Generating Stats...\r");
				fflush(0);
			}
			usleep(5000);
			i++;
		}
		printf("Stats can be found in stats.log\n");
	}
	printf("Thats bout it\n");
	// end
}