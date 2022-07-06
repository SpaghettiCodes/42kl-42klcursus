#include "ft_printf.h"
//               No switches?
// ⠀⣞⢽⢪⢣⢣⢣⢫⡺⡵⣝⡮⣗⢷⢽⢽⢽⣮⡷⡽⣜⣜⢮⢺⣜⢷⢽⢝⡽⣝
// ⠸⡸⠜⠕⠕⠁⢁⢇⢏⢽⢺⣪⡳⡝⣎⣏⢯⢞⡿⣟⣷⣳⢯⡷⣽⢽⢯⣳⣫⠇
// ⠀⠀⢀⢀⢄⢬⢪⡪⡎⣆⡈⠚⠜⠕⠇⠗⠝⢕⢯⢫⣞⣯⣿⣻⡽⣏⢗⣗⠏⠀
// ⠀⠪⡪⡪⣪⢪⢺⢸⢢⢓⢆⢤⢀⠀⠀⠀⠀⠈⢊⢞⡾⣿⡯⣏⢮⠷⠁⠀⠀
// ⠀⠀⠀⠈⠊⠆⡃⠕⢕⢇⢇⢇⢇⢇⢏⢎⢎⢆⢄⠀⢑⣽⣿⢝⠲⠉⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⡿⠂⠠⠀⡇⢇⠕⢈⣀⠀⠁⠡⠣⡣⡫⣂⣿⠯⢪⠰⠂⠀⠀⠀⠀
// ⠀⠀⠀⠀⡦⡙⡂⢀⢤⢣⠣⡈⣾⡃⠠⠄⠀⡄⢱⣌⣶⢏⢊⠂⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⢝⡲⣜⡮⡏⢎⢌⢂⠙⠢⠐⢀⢘⢵⣽⣿⡿⠁⠁⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠨⣺⡺⡕⡕⡱⡑⡆⡕⡅⡕⡜⡼⢽⡻⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⣼⣳⣫⣾⣵⣗⡵⡱⡡⢣⢑⢕⢜⢕⡝⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⣴⣿⣾⣿⣿⣿⡿⡽⡑⢌⠪⡢⡣⣣⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⡟⡾⣿⢿⢿⢵⣽⣾⣼⣘⢸⢸⣞⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠁⠇⠡⠩⡫⢿⣝⡻⡮⣒⢽⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀

int ft_intcase(int i, va_list ptr)
{
	if (i == 4 || i == 5)
		return (ft_count_int(va_arg(ptr, int)));
	else if (i == 6)
		return (ft_count_uint(va_arg(ptr, unsigned int), 10, 'U'));
	else if (i == 7)
		return (ft_count_uint(va_arg(ptr, unsigned int), 16, 'x'));
	else if (i == 8)
		return (ft_count_uint(va_arg(ptr, unsigned int), 16, 'X'));
}

int	ft_case(int i, va_list ptr)
{
	if (i >= 4 && i <= 8)
		return (ft_intcase(i, ptr));
	else if (i == 0)
		return (ft_put_char(va_arg(ptr, int)));
	else if (i == 1)
		return (ft_put_line(va_arg(ptr, char *)));
	else if (i == 2)
		return (ft_put_percent());
	else
		return (-1);
}

int ft_convertion(char c, va_list ptr)
{
	char	*flags;
	int		i;

	flags = "cs%pdiuxX";
	i = -1;
	while (flags[++i])
		if (flags[i] == c)
			return (ft_case(i, ptr));
	return (-1);
}

int ft_printf(const char *str, ...)
{
	int	i;
	int	printed;
	int	check;
	va_list ptr;

	i = -1;
	printed = 0;
	va_start(ptr, str);
	while (str[++i])
	{
		if (str[i] != '%' && ++printed)
			write(1, &str[i], 1);
		else
		{
			check = ft_convertion(str[i+1], ptr);
			if (str[i+1] != '%')
				va_arg(ptr, void *);
			if (check == -1)
				break;
			printed += check;
			i++;
		}
	}
	return (printed);
}
