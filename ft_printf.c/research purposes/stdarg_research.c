#include <stdarg.h>
#include <stdio.h>

int	add(va_list ptr)
{
	int a = va_arg(ptr, int);
	int b = va_arg(ptr, int);
	printf("%d + %d = %d\n",a,b,(a+b));
	return (a + b);
}

int	sum(int no_int, ...)
{
	static va_list ptr;
	int		sum;
	va_start(ptr, no_int);
	for (int i = 0; i < (no_int - 1); i++)
	{
		sum += add(ptr);
		va_arg(ptr, void *);
	}
	va_end(ptr);
	return (sum);
}

int main()
{
	int total = sum(5,1,2,3,4,5);
	printf("%d", total);
}
