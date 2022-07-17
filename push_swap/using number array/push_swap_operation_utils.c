void	swap(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
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

void	shift_left (int *dest, int size_dest)
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

void	push(int *src, int *size_src, int *dest, int *size_dest)
{
	if (!size_src)
		return ;
	*size_dest = *size_dest + 1;
	shift_right(dest, size_dest);
	swap(&dest[0], &src[0]);
	shift_left(src, size_src);
	*size_src = *size_src - 1;
	return ;
}
