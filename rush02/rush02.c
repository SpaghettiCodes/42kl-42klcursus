#include "rush02.h"
#define BUFF_SIZE 100

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = -1;
// 	while(str[++i]){};
// 	return (i);
// }

char *append(char *dest, char *source)
{
	char *ret;
	int	i;
	int j;

	printf("in append\n");

	ret = malloc(sizeof(char) * (ft_strlen(dest) + ft_strlen(source) + 1));

	i = 0;
	printf("copying...\n");
	while(dest && dest[i])
	{
		ret[i] = dest[i];
		i++;
	}

	printf("appending\n");
	j = 0;
	while(source && source[j])
	{
		ret[i] = source[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	printf("done appending\n");

	free(dest);
	printf("freed\n");

	return (ret);
}

int	ft_atoi(char *str)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = (ret * 10) + (str[i] - '0');
		i++;
	}
	return (ret);
}

char *transfer(char *str)
{
	int start;
	int end;
	int i;
	char *ret;

	start = 0;
	while(str[start] == ' ')
		start++;

	end = ft_strlen(str) - (ft_strlen(str) != 0);
	while(str[end] == ' ' && end != -1)
		end--;

	if (end < start)
		return NULL;

	ret = malloc (sizeof(char) * (end - start + 2));

	i = -1;
	while (start <= end)
		ret[++i] = str[start++];
	ret[i] = '\0';

	return (ret);
}

dictionary *create_dict(char **content)
{
	int	i;
	int	sep_loc;
	dictionary *ret;
	dictionary *current;

	printf("splitted, now creating dict...\n");
	ret = malloc(sizeof(dictionary));
	current = ret;
	i = -1;
	while (content[++i])
	{
		current->value = ft_atoi(content[i]);
		sep_loc = -1;
		while (content[i][++sep_loc] != ':'){};
		current->definition = transfer(&content[i][sep_loc + 1]);
		if (content[i + 1])
			current->next = malloc(sizeof(dictionary));
		else
			current->next = NULL;
		current = current->next;
	}
	return (ret);
}

dictionary *copy(int fd)
{
	char buff[BUFF_SIZE];
	char *contents;
	dictionary *dict;
	int check;

	contents = NULL;
	while (1)
	{
		check = read(fd, buff, (BUFF_SIZE - 1));
		if (!check || check == -1)
		{
			printf("broke out\n");
			break;
		}
		buff[check] = '\0';
		contents = append(contents, buff);
	}
	dict = create_dict(ft_split(contents));
	free(contents);
	return (dict);
}

int	lookup(int toread, dictionary *num_dic)
{

}

int main(int ac, char **av)
{
	int fd;
	int toread;
	dictionary *num_dic;

	if (ac == 3)
	{
		fd = open(av[1], O_RDWR);
		toread = ft_atoi(av[2]);
	}
	else if (ac == 2)
	{
		fd = open("numbers.dict", O_RDWR);
		toread = ft_atoi(av[1]);
	}
	else
		return (420);

	printf("fd = %d\n", fd);
	num_dic = copy(fd);
	printf("generated a number dictionary\n");
	sort_entry(num_dic);
	lookup(toread, num_dic);
	return (69);
}
