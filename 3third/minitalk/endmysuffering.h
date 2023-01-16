#ifndef ENDMYSUFFERING_H
# define ENDMYSUFFERING_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define BIT1 SIGUSR1
# define BIT0 SIGUSR2

int ft_print(char *str);
int ft_num(int num);
int	ft_atoi(char *nber);
int ft_strlen(char *str);
char *ft_append(char *src, char *dest);

#endif
