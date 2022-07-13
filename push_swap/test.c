void	swap(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
	return ;
}

void	shift(int *dest, int size_dest)
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

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *dest;
	dest = (int *) malloc (sizeof(int) * 10);

	for (int i = 0; i < 6; i++)
		dest[i] = i;

	int destnum = 10;

	printf("Before: \n");
	for (int i = 0; i < destnum; i++)
		printf("%d ", dest[i]);
	printf("\n");

	shift(dest, destnum);

	printf("After: \n");
	for (int i = 0; i < destnum; i++)
		printf("%d ", dest[i]);
	printf("\n");
}
