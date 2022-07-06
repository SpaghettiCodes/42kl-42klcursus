#ifndef FT_PRINTF_H
#define FT_PRINTF_H1

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int ft_printf(const char *, ...);

// %c
int		ft_put_char(int a);

// %s
int		ft_put_line(char *a);

// %u
void	ft_put_unsigned_int(unsigned int n);

// %d and %i
void	ft_put_int(int n);

// %x and %X
void	ft_put_int_base16(unsigned int n, char *base16);

// %%
int	ft_put_percent();

// count bytes placed (for integers)
int		ft_count_int(int n);
int		ft_count_uint(unsigned int n, int base, char format);

#endif
