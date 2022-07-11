#include "get_next_line.h"
#include <stdio.h>

// int main()
// {
// 	int fd;
// 	int	i;
// 	char *test;
// 	i = 0;
// 	fd = open("42_with_nl", O_RDONLY);
// 	while (1)
// 	{
// 		test = get_next_line(fd);
// 		if (!test)
// 		{
// 			printf("%d = from file 1: %s\n",i, test);
// 			break;
// 		}
// 		printf("%d = from file 1: %s\n",i, test);
// 		i++;
// 	}
// 	// char *test =  get_next_line(0);
// 	// printf("%s\n", test);
// }

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
	i = 0;
	fd = open("42_with_nl", O_RDONLY);
	while (1)
	{
		test = get_next_line(fd);
		if (!test)
		{
			printf("from file 1: \n%s\n",test);
			break;
		}
		ft_putstr("from file 1:\n");
		ft_putstr_non_printable(test); 
		printf("\n");
		i++;
	}
	// char *test =  get_next_line(0);
	// printf("%s\n", test);
}

