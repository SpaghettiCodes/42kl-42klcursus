#include "checker.h"

//shift all the elements in dest to the right by 1, the last element becomes the first
void	shift_right(int *dest, int size_dest)
{
	size_dest--;
	while (size_dest > 0)
	{
		swap(&dest[size_dest], &dest[size_dest - 1]);
		size_dest--;
	}
	return ;
}

//shift all the elements in dest to the left by 1, the first element becomes the last
void	shift_left(int *dest, int size_dest)
{
	int		i;

	i = 0;
	while (i < (size_dest - 1))
	{
		swap(&dest[i], &dest[i + 1]);
		i++;
	}
	return ;
}
void	reverserotate(int *tab, int size_tab)
{
	shift_right(tab, size_tab);
}

void	rotate(int *tab, int size_tab)
{
	shift_left(tab, size_tab);
}

#include <stdio.h>

void	push(int *src, int *size_src, int *dest, int *size_dest)
{
	if (!(*size_src))
		return ;
	*size_dest = *size_dest + 1;
	shift_right(dest, *size_dest);
	swap(&dest[0], &src[0]);
	shift_left(src, *size_src);
	*size_src = *size_src - 1;
	return ;
}
