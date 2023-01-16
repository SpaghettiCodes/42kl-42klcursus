#include "get_next_line_bonus.h"
#include <stdio.h>

// int main()
// {
// 	int fd;
// 	int fd2;
// 	char *test;
// 	int	i;
// 	char *test2;
// 	fd = open("test.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	i = 0;
// 	while (i < 10)
// 	{
// 		test = get_next_line(fd);
// 		test2 = get_next_line(fd2);
// 		printf("from file 1: %s\n",test);
// 		printf("from file 2: %s\n",test2);
// 		i++;
// 	}
// }

void	ft_putstr_non_printable(char *str)
{
	int		n;

	n = -1;
	if (!str)
		return ;
	while (str[++n])
	{
		if (str[n] < 32 || str[n] > 126)
		{
			write(1, "\\n", 2);
		}
		else
			write(1, &str[n], 1);
	}
}

void	ft_putstr(char *str)
{
	int n;
	n = -1;
	while (str[++n])
	{
		write(1, &str[n], 1);
	}
}

int main()
{
	int fd;
	int	i;
	char *test;
	char *test2;
	i = 0;
	char *test3;
	int fd2 = open("test2", O_RDONLY);
	fd = open("42_with_nl", O_RDONLY);
	int fd3 = open("test.txt", O_RDONLY);
	while (1)
	{
		printf("\n\n%d iteration = \n\n", i);
		test = get_next_line(fd);
		test2 = get_next_line(fd2);
		test3 = get_next_line(fd3);
		if (!test && !test2)
			break;
		if (!test)
		{
			printf("from file 1: \n%s\n",test);
		}
		else
		{
			ft_putstr("from file 1:\n");
			ft_putstr_non_printable(test);
			printf("\n");
		}
		if (!test2)
		{
			printf("from file 2: \n%s\n",test2);
		}
		else
		{
			ft_putstr("from file 2:\n");
			ft_putstr_non_printable(test2);
			printf("\n");
		}
		if (!test3)
		{
			printf("from file 3: \n%s\n",test3);
		}
		else
		{
			ft_putstr("from file 3:\n");
			ft_putstr_non_printable(test3);
			printf("\n");
		}
		i++;
	}
	// char *test =  get_next_line(0);
	// printf("%s\n", test);
}
