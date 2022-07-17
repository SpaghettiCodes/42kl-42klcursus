#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int				num;
	struct s_stack *next;
}	t_stack;

t_stack	*makestack(int ac, char **av);
int	ft_atoi(const char *str, t_stack *stack);

// push swap operations
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// utils
void	swap(t_stack **stack);
void	shift_right(t_stack **dest);
void	shift_left (t_stack **dest);
void	reverserotate(t_stack *tab);
void	rotate(t_stack *tab);
void	push(t_stack **src, t_stack **dest);
int		*int_dup(t_stack *a);

#endif
