void	printarr(int *dest, int destnum)
{
	for (int i = 0; i < destnum; i++)
	printf("%d ", dest[i]);
		printf("\n");
}


void	swap(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
	return ;
}

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

void	push(int *src, int size_src, int *dest, int size_dest)
{
	if (!size_src)
		return ;
	size_dest++;
	shift_right(dest, size_dest);
	swap(&dest[0], &src[0]);
	shift_left(src, size_src);
	size_src--;
	return ;
}

#include "stdlib.h"

void	leave()
{
	for (int i = 0; i < 4; i++)
	{
		if (i == 2)
			exit(3);
		printf("i = %d\n", i);
	}
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *dest;
	int *src;
	dest = (int *) malloc (sizeof(int) * 10);
	src = (int *) malloc (sizeof(int) * 10);

	for (int i = 0; i < 10; i++)
		src[i] = i;

	int destnum = 10;

	printf("Before: \n");
	printarr(dest, destnum);
	printarr(src, destnum);

	leave();

	// push(src, 10, dest, 0);

	// printf("After: \n");
	// printarr(dest, destnum);
	// printarr(src, destnum);

	// push(dest, 1, src, 9);

	// printf("After: \n");
	// printarr(dest, destnum);
	// printarr(src, destnum);

	// push(src, 10, dest, 0);
	// push(src, 9, dest, 1);
	// push(src, 8, dest, 2);

	// printf("After: \n");
	// printarr(dest, destnum);
	// printarr(src, destnum);

	shift_left(src, destnum);
	printarr(src, destnum);
}
