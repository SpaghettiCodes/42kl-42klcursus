#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	debug_print(int	fd, char *format, ...)
{
	va_list ptr;
	va_start(ptr, format);
	for (int i = 0; format[i]; i++)
	{
		if (format[i] == '%' && i++)
			debug_print(fd, va_arg(ptr, char *));
		write(fd, &format[i], 1);
	}
	va_end(ptr);
}

int main()
{
	debug_print(1, "ehe\n");
}