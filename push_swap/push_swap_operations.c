void	swap(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
	return ;
}

void	sa(int *a, int size_a)
{
	if (size_a < 2)
		return ;
	swap(&a[0], &a[1]);
	return ;
}

void	sb(int *b, int size_b)
{
	if (size_b < 2)
		return ;
	swap(&b[0], &b[1]);
	return ;
}

void	ss(int *a, int size_a, int *b, int size_b)
{
	sa(a, size_a);
	sb(b, size_b);
	return ;
}

void	shift_right(int *dest, int size_dest)
{
	size_dest--;
	while (size_dest != 1)
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

void	push(int *src, int size_src, int *dest, int size_dest)
{
	if (!size_src);
		return ;
	size_dest++;
	shift_right(dest, size_dest);
	swap(&dest[0], &src[0]);
	shift_left(src, size_src);
	size_src--;
	return ;
}

void	pa(int *a, int size_a, int *b, int size_b)
{
	push(b, size_b, a, size_a);
}

void	pb(int *b, int size_b, int *a, int size_a)
{
	push(a, size_a, b, size_b);
}

void	rotate(int *tab, int size_tab)
{
	
}
