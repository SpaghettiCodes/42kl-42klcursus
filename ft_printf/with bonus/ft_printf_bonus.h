#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int			ft_printf(const char *, ...);

typedef struct s_Properties{
	int		l_aligned;
	int		sign;
	int		place_space_front;
	int		width;
	int		place_space;
	int		place_zero;
	int		prefix;
	int		preci;
	char	type;
} t_properties;

// switch case
int				ft_intcase(t_properties *flag, va_list ptr);
int				ft_charcase(t_properties *flag, va_list ptr);
int				ft_convertion(t_properties *flag, va_list ptr);
int				format_handler(t_properties *flag, char *c, va_list ptr, int *printed);
int				check_width(t_properties *flag, char c);
int				checktype(t_properties *flag, char c);


// handlers
int				ft_char_handler(t_properties *flag, va_list ptr);
int				ft_int_handler(t_properties* flag, va_list ptr);
int				ft_uint_handler(t_properties* flag, va_list ptr);
int				ft_base16_handler(t_properties* flag, va_list ptr);
int				ft_ptr_handler(t_properties* flag, va_list ptr);
int				ft_none_handler(t_properties *flag);
int				ft_char_width_handler(t_properties* flag, int printed);
int				ft_int_width_handler(t_properties* flag, int printed);

// flag handlers
t_properties	*ft_initialize_flag();
void			ft_reset_flag(t_properties *flag);
int				print_flag(t_properties *flag, va_list ptr, int *printed);
int				ft_print_l_aligned(t_properties *flag, int printed);
int				ft_place_preci(t_properties *flag, int digits);
int				ft_base16_putprefix(t_properties* flag);
int				check_flag(t_properties *flag, char c);
int				check_width(t_properties *flag, char c);


// %c
int				ft_put_char(int a);

// %s
int				ft_str_print(char *a, t_properties *flag);
int				ft_put_null(t_properties *flag);

// %p
void			ft_put_ptraddr(uintptr_t n, char *base16);

// %u
void			ft_put_unsigned_int(unsigned int n);

// %d and %i
void			ft_put_int(int n);

// %x and %X
void			ft_put_int_base16(unsigned int n, char *base16);

// %%
int				ft_put_percent();

// count bytes placed
int				ft_count_int(int n);
int				ft_count_uint(unsigned int nbr, int base);
int				ft_count_ptraddr(uintptr_t ptraddr);
int				ft_strlen(char *a);

// atoi
int				ft_atoi(const char *str);

#endif
