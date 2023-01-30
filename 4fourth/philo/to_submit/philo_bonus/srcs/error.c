#include "philo.h"

int	eprint(char *err_msg)
{
	return (write(2, err_msg, str_len(err_msg)));
}