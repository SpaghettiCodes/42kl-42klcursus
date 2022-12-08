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

void	gen_num(int write_file, int write_pipe, char **envp, int count, int seed, int len)
{
	char check[len];
	char *args[len + 2];
	int	numbers[len], pfd[2];
	int	num;
	int	childpid;

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

	args[0] = "./pushswap";
	for (int i = 1; i < (len + 1); i++)
		args[i] = itoa(numbers[i - 1]);
	args[len + 1] = 0;

	dup2(write_file, STDOUT_FILENO);
	close(write_file);
	printf("--- Test %d Numbers ---\n", count);
	for (int i = 0; i < len; i++)
		printf("%d ", numbers[i]);
	printf("\n\n");

	dup2(write_pipe, STDOUT_FILENO);
	close(write_pipe);
	if(execve("./your_ps/pushswap", args, envp) == -1)
		printf("Something went wrong LMAO\n");
}

int	runtest(int test_numfd, int step_takenfd, int count, char **envp, int seed, int len)
{
	int pfd[2];
	int	childpid;

	//1 is writing 0 is reading
	pipe(pfd);	
	childpid = fork();
	if (!childpid)
	{
		close(pfd[0]);
		close(step_takenfd);
		gen_num(test_numfd, pfd[1], envp, count, seed, len);
	}
	else
	{
		close(test_numfd);
		close(pfd[1]);
		waitpid(childpid, NULL, 0);
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
	printf("NUMBER LENGTH = %d\n", cases_len);
	printf("CASES = %d\n", cases);
	printf("AVERAGE STEPS = %d\n", average(result, cases));
	int max_val = max(sorted_result, cases);
	printf("LARGEST MOVES = %d\n", max_val);
	printf("WORST CASE = %d\n", find(result, cases, max_val) + 1);
	exit(10);
}

int main(int ac, char **av, char **envp)
{
	if (ac < 3)
		return (printf("Include test count and/or array length!\nExecute the program with the following arguments - ./test [number of test cases] [length of numbers]\n"));
	int	gen_count = atoi(av[1]);
	int	arr_len = atoi(av[2]);
	
	if (access("./your_ps/", F_OK))
		return(printf("folder is gone\n"));

	system("cd ./your_ps && make");

	if (access("./your_ps/pushswap", X_OK))
		return(printf("Brother did you forget your makefile or something?\n"));
	printf("Pushswap prog found\n");

	int	test_num, step_taken, count, childpid;
	unsigned int seed = time(NULL);

	test_num = open("./data/test_nums.log", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	step_taken = open("./data/step_taken.log", O_WRONLY | O_TRUNC | O_CREAT, 0777);

	count = 1;
	printf("Please wait...\n");
	printf("In the meantime, go get something to eat\n");
	while (count <= gen_count)
	{
		childpid = fork();
		if (!childpid)
			runtest(test_num, step_taken, count, envp, seed, arr_len);
		else
		{
			waitpid(childpid, NULL, 0);
			fflush(0);
			printf("Generated %d/%d cases\r", count, gen_count);
			fflush(0);
			count++;
			seed--;
		}
	}
	printf("Done! Generated %d test cases\n", --count);
	close(test_num);
	printf("Everything is in the data folder\n");
	printf("Numbers used in testing is in test_num.log\n");
	printf("Number of step Taken is recorded in step_taken.log\n");
	printf("You have to wait for a while for a new seed to be determined (seed is based on the time)\n");	

	printf("Generating Stats..\n");
	childpid = fork();
	if (!childpid)
		stats(gen_count, arr_len);
	else
	{
		waitpid(childpid, NULL, 0);
		printf("Stats can be found in stats.log\n");
	}
}