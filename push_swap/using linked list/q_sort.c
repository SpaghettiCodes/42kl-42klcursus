#include "pushswap.h"

void q_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int q_partition(int *tab, int first, int last)
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
			q_swap(&tab[i], &tab[j]);
			i++;
		}
		j++;
	}
	q_swap(&tab[i], &tab[last]);
	return (i);
}

int q_sort(int *tab, int first, int last)
{
	int	pivot;

	if (last <= first)
		return (0);
	pivot = q_partition(tab, first, last);
	q_sort(tab, pivot + 1, last);
	q_sort(tab, first, pivot - 1);
}
