#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *tab, int first, int last)
{
	int	i;
	int	j;
	int pivot;

	i = first;
	j = i;
	pivot = tab[last];
	while (j < last)
	{
		if (tab[j] <= pivot)
		{
			swap(&tab[i], &tab[j]);
			i++;
		}
		j++;
	}
	swap(&tab[i], &tab[last]);
	return (i);
}

int q_sort(int *tab, int first, int last)
{
	int	pivot;

	if (last <= first)
		return (0);
	pivot = partition(tab, first, last);
	q_sort(tab, pivot + 1, last);
	q_sort(tab, first, pivot - 1);
}

int	*int_dup(int ac, char **av)
{
	int	*list;
	int	i;
	int	j;

	list = malloc((ac-1) * sizeof(int));
	i = -1;
	j = 1;

	while (++i < ac)
	{
		list[i] = atoi(av[j]);
		j++;
	}
	q_sort(list, 0, (ac-1)-1);
	return (list);
}

int main(int ac, char **av)
{
	int *test = int_dup(ac, av);

	for (int i = 0; i < (ac-1); i++)
		printf("%d ", test[i]);
}
