#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

// the struct
typedef struct s_pushswap
{
	int	*sorted;
	int	*stack_a;
	int	*stack_b;
	int	a_size;
	int	b_size;
	int	total_size;
}	t_pushswap;

// atoi
int		ft_atoi(const char *str, t_pushswap *stacks);

// push swap operations
void	sa(t_pushswap *stack);
void	sb(t_pushswap *stack);
void	ss(t_pushswap *stack);
void	pa(t_pushswap *stack);
void	pb(t_pushswap *stack);
void	ra(t_pushswap *stack);
void	rb(t_pushswap *stack);
void	rr(t_pushswap *stack);
void	rra(t_pushswap *stack);
void	rrb(t_pushswap *stack);
void	rrr(t_pushswap *stack);

// utils
void	swap(int *num1, int *num2);
void	shift_right(int *dest, int size_dest);
void	shift_left (int *dest, int size_dest);
void	reverserotate(int *tab, int size_tab);
void	rotate(int *tab, int size_tab);
void	push(int *src, int *size_src, int *dest, int *size_dest);
int		*int_dup(int *a, int size_a);

// solve
void	solve(t_pushswap *stack);
int		solve_two(t_pushswap *stack);
int		solve_three(t_pushswap *stack);
void	solve_small_big(t_pushswap *stack);
void	solve_very_big(t_pushswap *stack);
int		smallest_loc(int *stack, int stack_size);

// error
int		error(t_pushswap *stack);
// printstack for debug
void	printstack(t_pushswap *stacks);

// solving stacks
void	shift_to_correct(t_pushswap *stack, int larger, int toplace);
void	action(t_pushswap *stack, int toplace);
int		larger_than(int *stack, int reference, int stack_size);
int		moves(int larger_than, int smallest_loc, int stack_size);
void	search_and_add(t_pushswap *stack);


#endif
