#ifndef FT_PRINTF_H
#define FT_PRINTF_H1

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *, ...);

// Attempt on structures (end my suffering)
typedef struct Properties{
	int		l_aligned;			// -
	int		sign;				// + prints out the + sign
	int		place_space_front;	// (space)
	int		width;				// minimum width pice of shit (minimum bytes needed to be printed KILL MEEEE)
	int		place_space;		// if width has no specifier (n)
	int		place_zero;			// 0
	int		prefix;				// #
	int		preci;				// . (for char, maximum bytes that can be printed) (for int, a 2nd width that is more annoying)
	char	type;				// what type of thingy are we dealing with
} properties;

// switch case
int			ft_intcase(properties *flag, va_list ptr);
int			ft_charcase(properties *flag, va_list ptr);
int			ft_convertion(properties *flag, va_list ptr);
int			format_handler(properties *flag, char *c, va_list ptr, int *printed);
int			check_flag(properties *flag, char c);
int			check_width(properties *flag, char c);
int			checktype(properties *flag, char c);


// handlers
int			ft_char_handler(properties *flag, va_list ptr);
int			ft_int_handler(properties* flag, va_list ptr);
int			ft_uint_handler(properties* flag, va_list ptr);
int			ft_base16_handler(properties* flag, va_list ptr);

// flag handlers
properties	*ft_initialize_flag();
void		ft_reset_flag(properties *flag);
int			print_flag(properties *flag, va_list ptr, int *printed);
int			ft_print_l_aligned(properties *flag, int type, int printed);


// %c
int			ft_put_char(int a);

// %s
int			ft_put_line(char *a, int preci);

// %p
void		ft_put_ptraddr(uintptr_t n, char *base16);

// %u
void		ft_put_unsigned_int(unsigned int n);

// %d and %i
void		ft_put_int(int n);

// %x and %X
void		ft_put_int_base16(unsigned int n, char *base16);

// %%
int			ft_put_percent();

// count bytes placed (for integers)
int			ft_count_int(int n);
int			ft_count_uint(unsigned int nbr, int base);
int			ft_count_ptraddr(void *ptr);

// atoi
int			ft_atoi(const char *str);

#endif
