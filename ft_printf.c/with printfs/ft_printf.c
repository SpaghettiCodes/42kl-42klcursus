#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	int	i;
	int	printed;
	int	initial;
	va_list ptr;
	properties *flag;

	i = -1;
	printed = 0;
	va_start(ptr, str);
	while (str[++i])
	{
		if (str[i] != '%')
			printed += ft_put_char(str[i]);
		else
		{
			flag = ft_initialize_flag();
			initial = i;
			i += format_handler(flag, (char *)&str[i], ptr, &printed);
			free(flag);
			if (i == initial)
				printed += ft_put_char('%');
		}
	}
	return (printed);
}

int main()
{
	int		x = 123123;
	int		cmp1, cmp2;
	char *s = "helpme";
	printf("TEST 1-\n");
	cmp1 = ft_printf("%-012dend\n", x);
	cmp2 = printf("%-012dend\n", x);
	printf("\n\nDiff in values = \nmy funct = %d, sys funct = %d", cmp1, cmp2);
}
