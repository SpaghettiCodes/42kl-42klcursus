#ifndef FT_PRINTF_H
#define FT_PRINTF_H1

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *, ...);

// switch case
int		ft_intcase(char *i, va_list ptr);
int		ft_charcase(char *i, va_list ptr);
int		ft_convertion(char *i, va_list ptr);

// %c
int		ft_put_char(int a);

// %s
int		ft_put_line(char *a);

// %p
void	ft_put_ptraddr(uintptr_t n, char *base16);

// %u
void	ft_put_unsigned_int(unsigned int n);

// %d and %i
void	ft_put_int(int n);

// %x and %X
void	ft_put_int_base16(unsigned int n, char *base16);

// %%
int		ft_put_percent();

// count bytes placed (for integers)
int		ft_count_int(int n);
int		ft_count_uint(unsigned int n, unsigned int base, char format);
int		ft_count_ptraddr(void *ptr);

#endif
